/*
Name: Harikrishna P
Data: 07/02/2025
Project: LSB Image Steganography
*/

#include <stdio.h>
#include "encode.h"
#include "types.h"
#include <string.h>
#include "decode.h"

OperationType check_operation_type(char *argv[])  //check_operation_type function to check if we need to encode or decode. -e for encode -d for decode
{
    if ( (strcmp(argv[1], "-e") ) == 0 ) 
        return e_encode;
    else if ( (strcmp(argv[1], "-d") ) == 0 ) 
        return e_decode;
    else
        return e_unsupported;
}




int main(int argc, char *argv[])
{
    if ( argc < 2 || argc > 5 )                           //Checking if the user has entered required number of CLA or not
    {   
        printf("ERROR : Invalid usage!!!\nFor Encoding\n./a.out -e Beautiful.bmp secret.txt [stegno.bmp]\n");
        printf("For Decoding : \n./a.out -d Stegno.bmp data.txt\n");
        return 1;
    }
    else
    {
        EncodeInfo E1;
        DecodeInfo D1;
        int res = check_operation_type(argv); 
        if ( res == e_encode )
        {
            
            if ( argc >= 4)
            {
                printf("INFO : Selected Encoding\n");
                if ( read_and_validate_encode_args( argv, &E1 ) == e_success )     //if the mode is encoding then we have to validate encoding arguments
                {
                    printf("INFO : Successfully validated the arguments passed\n");
                    if ( do_encoding(&E1) == e_success )
                    {
                        printf("#####DONE : Encoding completed successfully :)#####\n");
                    }
                    else
                    {
                        printf("ERROR : Failed to encode:(\n");
                        return 1;
                    }
                }
                else
                {
                    printf("ERROR : Failed to validate the arguments passed\nUse .bmp & .txt files\n");
                    return 1;
                }
            }
            else
            {
                printf("Error\n");
            }


        }
        else if ( res == e_decode )
        {
            if(argc >= 3)
            {
                printf("INFO : Selected Decoding\n");
                if ( read_and_validate_decode_args( argv, &D1) == e_success )
                {
                    printf("INFO : Successfully validated the arguments passed.\n");
                    if (do_decoding(&D1) == e_success )
                    {
                        printf("#####DONE : Decoding completed successfully :)#####\n");
                    }
                    else
                    {
                        printf("ERROR : Failed to decode:(\n");
                    }
                }
                else
                {
                    printf("ERROR : Failed to validate the arguments passed\nUse .bmp & .txt files\n");
                    return 1;
                }
            }
            else
            {
                printf("Error\n");
            }
        }
        else
        {
            printf("ERROR : Unsupported Operation\n");
            printf("For Encoding : \n./a.out -e Beautiful.bmp secret.txt [stegno.bmp]\n");
            printf("For Decoding : \n./a.out -d Stegno.bmp data.txt\n");
            return 1;
        }
    }

}
