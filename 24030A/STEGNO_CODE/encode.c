#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>

/* Function Definitions */

/* Get image size
 * Input: Image file ptr

 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    rewind (fptr_image);
    return width * height * 3;
}

/* 
 * Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

    	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);

    	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
    	perror("fopen");
    	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);

    	return e_failure;
    }

    // No failure return e_success
    return e_success;
}



Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)   //To valiade the CLA for encoding
{

    if ( strcmp( ( strstr( argv[2], "." ) ), ".bmp" ) == 0 ) //strstr function is used to get the addr of . and then it is chceked with ".bmp" using strcmp
    {
        encInfo->src_image_fname = argv[2];                  //storing 2nd CLA which is the image file name to EncodeInfo struct memeber src_image_fname
    }
    else
        return e_failure;

    if ( strcmp( ( strstr( argv[3], "." ) ), ".txt" ) == 0 )  //checking if the 3 CLA is of .txt extension or not. 
    {
        encInfo->secret_fname = argv[3];                      //storing in secret_fname
    }
    else
        return e_failure;

    if ( argv[4] != NULL )                              //Checking if output file is passed or not
    {
        encInfo->stego_image_fname = argv[4];           //if passed then store it in stego_image_fname
    }
    else
    {
        printf("INFO : Output file name not mentioned. Creating default.bmp\n");
        encInfo->stego_image_fname = "default.bmp";     //if not passed the output file name is default.bmp
    }
    return e_success;
}


uint get_file_size(FILE *fptr)                        //To get the secret file size
{
    fseek(fptr,0,SEEK_END);
    return ftell(fptr);
}


Status check_capacity(EncodeInfo *encInfo)            //To check if the secret msg fits in image
{
    encInfo->image_capacity = get_image_size_for_bmp(encInfo->fptr_src_image);
    encInfo->size_secret_file = get_file_size(encInfo->fptr_secret);
    if ( (encInfo->image_capacity) > (16 + 32 + 32 + 32 + (encInfo->size_secret_file * 8 ) ) )
        return e_success;
    else
        return e_failure;
}


Status copy_bmp_header(EncodeInfo *encInfo)           //To copy bmp header to the output file
{
    char str[54];
    fseek(encInfo->fptr_src_image,0,SEEK_SET);
    fread(str,54,1,encInfo->fptr_src_image);
    fwrite(str,54,1,encInfo->fptr_stego_image);
    return e_success;
}

Status encode_byte_to_lsb(char data, char *image_buffer)        //Encoding happens here
{
    for(int i = 0 ; i < 8 ; i++)
    {
        image_buffer[i] = (image_buffer[i] & 0xFE) | ((data>>i) & 1);  //we will be doing & operaton with 0xFE to clear the lsb of each byte and then take each bit of our data and set that into the byte
    }
}


Status encode_data_to_image(char *data, int size, EncodeInfo *encInfo)       //To encode characters 
{
    for(int i = 0 ; i < size ; i++)
    {
        fread(encInfo->image_data, 8, 1, encInfo->fptr_src_image);  //reading 8 bytess from src_image file
        encode_byte_to_lsb(data[i], encInfo->image_data);           //encoding 1 char in 8 bytes
        fwrite(encInfo->image_data,8,1,encInfo->fptr_stego_image);  //writing encoded data in dest image
    }

}


Status encode_magic_string(char *magic_string, EncodeInfo *encInfo)   //To encode magic string
{
    encode_data_to_image(magic_string, strlen(magic_string), encInfo);
    return e_success;
}


Status encode_size_to_lsb(int size,EncodeInfo *encInfo)    //To encode integer values
{
    char str[32];
    fread(str, 32, 1, encInfo->fptr_src_image);
    for(int i = 0 ; i < 32 ; i++)
    {
        str[i] = (str[i] & 0xFE) | ((size>>i) & 1);
    }
    fwrite(str, 32, 1, encInfo->fptr_stego_image);
}



Status encode_secret_file_extn_size(int size,EncodeInfo *encInfo)    //To encode secret file extn size
{
    encode_size_to_lsb(size,encInfo);
    return e_success;
}


Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo)   //To encode secret file extn
{
    encode_data_to_image(file_extn, strlen(file_extn), encInfo);
    return e_success;
}


Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)    //To encode secret file size
{
    encode_size_to_lsb(file_size, encInfo);
    return e_success;
}


Status encode_secret_file_data(EncodeInfo *encInfo)                   //To encode secret file data
{
    char str[encInfo->size_secret_file];
    fseek(encInfo->fptr_secret,0,SEEK_SET);
    fread(str, encInfo->size_secret_file,1,encInfo->fptr_secret);
    encode_data_to_image(str,encInfo->size_secret_file,encInfo);
    return e_success;
}


Status copy_remaining_img_data(EncodeInfo *encInfo)                   //copying remaining data
{
    int len = encInfo->image_capacity + 54 -  (ftell(encInfo->fptr_src_image));
    char str[len];
    fread(str,len,1,encInfo->fptr_src_image);
    fwrite(str,len,1,encInfo->fptr_stego_image);
    return e_success;
}



Status do_encoding(EncodeInfo *encInfo)                 //Function to start encoding all the proccess for encoding will be called from this function
{
    if (open_files(encInfo) == e_success )              //Opening all the files 
    {
        printf("INFO : Successfully opened files\n");
        if ( check_capacity(encInfo) == e_success )       //Checking if the secret msg fits in image
        {
            printf("INFO : Secret file can be encoded into the image file.\n");
            if ( copy_bmp_header(encInfo) == e_success )     //To copy the bmp header to stego file
            {
                printf("INFO : Successfully copied bmp header.\n");
                if ( encode_magic_string(MAGIC_STRING, encInfo ) == e_success )   //Encoding magic string
                {
                    printf("INFO : Encoded magic string successfully.\n");

                    strcpy(encInfo->extn_secret_file, strstr( encInfo->secret_fname, "."));     //Getting the extn from secret_fname and storing it in extn_secret_file
                    if ( encode_secret_file_extn_size(strlen(encInfo->extn_secret_file), encInfo) == e_success )  //Encoding secrect file extn size
                    {
                        printf("INFO : Encoded secret file extension size successfully.\n");
                        if ( encode_secret_file_extn(encInfo->extn_secret_file, encInfo) == e_success )  //Encoding secret  file extn
                        {
                            printf("INFO : Encoded secreet file extension successfully.\n");
                            if ( encode_secret_file_size(encInfo->size_secret_file, encInfo) == e_success )   //Encoding secret file size
                            {
                                printf("INFO : Encoded secret file size successfully.\n");
                                if ( encode_secret_file_data(encInfo) == e_success )           //Encoding secret file data
                                {
                                    printf("INFO : Encoded secret file data successfully.\n");
                                    if ( copy_remaining_img_data(encInfo) == e_success )     //Copying remaing data
                                    {
                                        printf("INFO : Remaining data copied successfully.\n");
                                    }
                                    else
                                    {
                                        printf("ERROR : Failed to copy the remaining data.\n");
                                    }
                                }
                                else
                                {
                                    printf("ERROR : Failed to encode secret file data.\n");
                                    return e_failure;
                                }
                            }
                            else
                            {
                                printf("ERROR : Failed to encode secret file size.\n");
                                return e_failure;
                            }
                        }
                        else
                        {
                            printf("ERROR : Failed to encode secret file extenstion.\n");
                        return e_failure;
                        }
                    }
                    else
                    {
                        printf("ERROR : Failed to encode secret file extenstion size.\n");
                    }

                }
                else
                {
                    printf("ERROR : Failed to encode magic string.\n");
                }

            }
            else
            {
                printf("ERROR : Unable to copy bmp header.\n");
                return e_failure;
            }
        }
        else
        {
            printf("ERROR : Secret file can't be encoded into the image file. Inadequate size of image file\n");
        }
    }
    else
    {
        printf("ERROR : Failed to open files\n");
        return e_failure;
    }
    return e_success;
}


