#ifndef DECODE_H
#define DECODE_H

#include "types.h"

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo
{
	/* Stego Image Info */
	char *stego_image_fname;
	FILE *fptr_stego_image;
	char image_data[MAX_IMAGE_BUF_SIZE];
	
	/*Magic string info*/
	char magic_string_data[3];
	
	/* Secret File Info */
	char *secret_fname;
	FILE *fptr_secret;
	char extn_secret_file[MAX_FILE_SUFFIX];
	int secret_file_extn_size;
	char secret_data[MAX_SECRET_BUF_SIZE];
	long size_secret_file;

} DecodeInfo;

/* Decoding function prototype */

/* Read and validate Decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* Get File pointers for i/p and o/p files */
Status open_decode_files(DecodeInfo *decInfo);

/* Decode Magic String */
Status decode_magic_string(char *magic_string, DecodeInfo *decInfo);

/*Decode secret file extension size*/
Status decode_secret_file_extension_size(DecodeInfo *decInfo);

/*Decode lsb to size*/
uint decode_lsb_to_size(int size, DecodeInfo *decInfo);

/*Decode secret file extension*/
Status decode_secret_file_extension(DecodeInfo *decInfo);

/*Decode lsb to data*/
Status decode_lsb_to_data(char *data, char *str, int size);

/*Decode secret file size*/
Status decode_secret_file_size(DecodeInfo *decInfo);

/*Decode secret file data*/
Status decode_secret_file_data(DecodeInfo *decInfo);

#endif
