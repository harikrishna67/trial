#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i=1 , empty;
    while(argv[i] != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("\033[1;33mWARNING : File %s is not available\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\033[0m\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("\033[1;33mWARNING : File %s is not having any contents\n" , argv[i]);
	    printf("Hence we are not adding that file into file linked list\033[0m\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head , argv[i]);

	    if(ret_val == SUCCESS)
	    {
		printf("\033[1;32mDONE : Successfully inserted the file : %s into file linked list\033[0m\n" , argv[i]);
		i++;
	    }
	    else if(ret_val == REPEATATION)
	    {
		printf("\033[1;33mWARNING : The file : %s is repeated. Do not add that file into file linked list\033[0m\n", argv[i]);
		i++;
	    }
	    else
	    {
		printf("Failure\n");
	    }
	}
    }
}

//fun() is used to check whether files available or not
// to check for file contents

int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
	return FILE_EMPTY;
    }
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //If list is empty
    if (*f_head == NULL)
    {
	Flist *new = malloc(sizeof(Flist));
	if (new == NULL)
	{
	    return FAILURE;
	}
	strcpy(new -> file_name, name);
	new -> link = NULL;
	*f_head = new;
	return SUCCESS;
    }
    Flist *temp = *f_head;
    
    while (temp -> link)
    {
	if (strcmp(temp -> file_name, name ) == 0)
	{
	    return REPEATATION;
	}
	temp = temp -> link;
    }
    //To check if file is already exists or not
    if (strcmp(temp -> file_name, name) == 0)
    {
	return REPEATATION;
    }
   
    Flist *new = malloc(sizeof(Flist));
    if (new == NULL)
    {
	return FAILURE;
    }
    strcpy(new -> file_name, name);
    new -> link = NULL;
    temp -> link = new;
    return SUCCESS;
}




