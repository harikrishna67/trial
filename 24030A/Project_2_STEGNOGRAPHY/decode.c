#include <stdio.h>
#include "decode.h"
#include "types.h"
#include "common.h"
#include <string.h>

Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo)
{
    if ( strcmp( ( strstr( argv[2] , "." ) ), ".bmp" ) == 0 )
    {
        decInfo->stego_image_fname = argv[2];
    }
    else
        return e_failure;
    if ( argv[3] != NULL )
    {
		if ( strcmp( ( strstr( argv[3] , "." ) ), ".txt" ) == 0 )
		{
			decInfo->secret_fname = argv[3];
		}
		else
			return e_failure;
    }
    else
    {
        printf("INFO : Output file not mentioned. Creating default.txt\n");
        decInfo->secret_fname = "default.txt";
    }
    return e_success;
}

Status open_decode_files(DecodeInfo *decInfo)
{
	//Stego image file
	decInfo->fptr_stego_image = fopen(decInfo->stego_image_fname, "r");
	//Error handling
	if (decInfo->fptr_stego_image == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);
        return e_failure;
    }

	//Decoded file
	 decInfo->fptr_secret = fopen(decInfo->secret_fname, "w");
    // Do Error handling
    if (decInfo->fptr_secret == NULL)
    {
        perror("fopen");
        fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->secret_fname);
        return e_failure;
	}
	return e_success;

}


Status decode_magic_string(char *magic_string, DecodeInfo *decInfo)
{

    int len = strlen(magic_string);
    char data[len];
    char str[len*8];
    fseek(decInfo->fptr_stego_image,54,SEEK_SET);
    fread(str,len*8,1,decInfo->fptr_stego_image);
    for(int i = 0 ; i < len ; i++)
    {
        data[i] = 0;
        for(int j = i*8 ; j < ((i+1) * 8 ) ; j++ )
        {
            data[i] = data[i] | ((str[j] & 1) << (j - 8*i) );
        }
    }
    if (strcmp(data,MAGIC_STRING) == 0)
        return e_success;
    else
        return e_failure;
}



Status decode_secret_file_extension_size(DecodeInfo *decInfo)
{
    decInfo->secret_file_extn_size  = decode_lsb_to_size(4,decInfo);
    if(decInfo->secret_file_extn_size != 0)
        return e_success;
    else
        return e_failure;
}



uint decode_lsb_to_size(int size, DecodeInfo *decInfo)
{
    int data[size];
    char str[size*8];
    fread(str, 8*size, 1, decInfo->fptr_stego_image);
    for(int i = 0 ; i < size ; i++)
    {
        data[i] = 0;
        for(int j = i*8; j < ( (i+1) * 8 ) ; j++ )
        {
            data[i] = data[i] | ((str[j] & 1) << (j - 8*i));
        }
    }
    return *data;
}




Status decode_secret_file_extension(DecodeInfo *decInfo)
{
    char str[32];
    char data[4];
    fread(str,32, 1, decInfo->fptr_stego_image);
    decode_lsb_to_data(data,str,4);
    strcpy(decInfo->extn_secret_file,data);
    if( ( decInfo->extn_secret_file[0]) != '\0')
        return e_success;
    else
        return e_failure;
}




Status decode_lsb_to_data(char *data, char *str, int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        data[i] = 0;
        for(int j = i*8 ; j < ((i+1) * 8 ); j++ )
        {
            data[i] = data[i] | ((str[j] & 1) << (j - 8*i));
        }
    }
}




Status decode_secret_file_size(DecodeInfo *decInfo)
{
    decInfo->size_secret_file = decode_lsb_to_size(4,decInfo);
    return e_success;
}




Status decode_secret_file_data(DecodeInfo *decInfo)
{
    int size = decInfo->size_secret_file;
    char data[size];
    char str[size*8];
    fread(str,size*8,1,decInfo->fptr_stego_image);
    decode_lsb_to_data(data,str,size);
    fwrite(data,size,1,decInfo->fptr_secret);
    return e_success;
}
       



Status do_decoding(DecodeInfo *decInfo)
{
	if ( open_decode_files(decInfo) == e_success )
	{
		printf("INFO : Opened required files.\n");
		if ( decode_magic_string( MAGIC_STRING, decInfo ) == e_success)
		{
			printf("INFO : Magic string found.\nStaring decodeing process...\n");    //Looking for magic string
			if ( decode_secret_file_extension_size(decInfo) == e_success )
			{
				printf("INFO : Decoded file extension size successfully.\n");     //call for decoding file extention size
				if ( decode_secret_file_extension(decInfo) == e_success)
				{
					printf("INFO : Decoded file extension successfully.\n");     //call for decoding file extention
					if (decode_secret_file_size(decInfo) == e_success)
					{
						printf("INFO : Decoded secret file size successfully.\n");    //call for decoding secret file size
						if (decode_secret_file_data(decInfo) == e_success)
						{
							printf("INFO : Decoded secret file data successfully.\n");  //call for decoding secret file data
						}
						else
						{
							printf("ERROR : Failed to decode secret file data\n");
							return e_failure;
						}
					}
					else
					{
						printf("ERROR : Failed to decode secret file size.\n");
						return e_failure;
					}
				}
				else
				{
					printf("ERROR : Failed to decode file extenstion.\n");
					return e_failure;
				}

			}
			else
			{
				printf("ERROR : Failed to decode file extenstion size.\n");
				return e_failure;
			}
		}
		else
		{
			printf("ERROR : Unable to find Magic string decoding can't be done on this file\n");
			return e_failure;
		}
	}
	else
	{
		printf("ERROR : Failed to open required files.\n");
		return e_failure;
	}
	return e_success;
}


