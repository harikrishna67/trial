#include "inverted_search.h"

 void update_database( Wlist *head[], Flist **f_head)
{
    //promot the user for new file name
    char file_name[FNAME_SIZE];
    printf("Enter the the file name\n");
    scanf("%s" , file_name);
    
    //validate
	int empty = isFileEmpty(file_name);
    if(empty == FILE_NOTAVAILABLE)
    {
        printf("\033[1;33mWARNING : File %s is not available\n" , file_name);
        printf("          Hence we are not adding that file into file linked list\033[0m\n");
    }
    else if(empty == FILE_EMPTY)
    {
        printf("\033[1;33m");
        printf("\033[1;33mWARNING : File %s is not having any contents\n" , file_name);
        printf("          Hence we are not adding that file into file linked list\033[0m\n");
    }
	else
    {
        int ret_val = to_create_list_of_files(f_head , file_name);

        if(ret_val == SUCCESS)
        {
            printf("\033[1;32mDONE : Successfully inserted the file : %s into file linked list.\033[0m\n" , file_name);
			//Update database
			Flist *temp = *f_head;
			while(temp)
            {
        		if(!strcmp( temp -> file_name , file_name))
        		{
            		create_database(temp , head);
        		}
        		temp  = (temp -> link);
    		}
        }
        else if(ret_val == REPEATATION)
        {
            printf("\033[1;33mWARNING : The file : %s is repeated. Do not adding that file into file linked list\033[0m\n", file_name);
        }
        else
        {
            printf("Failure\n");
        }
	}
}
