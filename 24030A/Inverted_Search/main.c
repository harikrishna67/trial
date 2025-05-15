
#include "invert.h"

int main(int argc, char *argv[])
{
	int option,cflag = 0,uflag = 0;
	Slist *head = NULL;
	hash_t arr[27];

	if(argc < 1)
	{
		printf("ERROR: ARGUMENTS NEED TO PASS\n");
		return FAILURE;
	}
	else
	{
		if(read_validate(argc,argv,&head) != FAILURE)
	        {
			printf("READ AND VALIDATE DONE\n");
			print_list(head);
	        }
	        else
		{
			printf("ERROR: INVALID\n");
	        }
	}
	if(head == NULL)
	{
		return FAILURE;
	}

	while(1)
	{
		printf("\n");
	        printf("1. CREATE DATABASE\n");
	        printf("2. DISPLAY DATABASE\n");
	        printf("3. SEARCH DATABASE\n");
	        printf("4. SAVE DATABASE\n");
	        printf("5. UPDATE DATABASE\n");
	        printf("6. EXIT\n");
	        printf("ENTER YOU OPTION\n");
	        scanf("%d",&option);
		switch(option)
	        {
			case 1:
				if(cflag || uflag)
				{
					printf("ERROR: DATABASE ALREADY CREATED\n");
				}
				else if(create_database(arr,&head) == SUCCESS)
				{
					cflag = 1;
					printf("CREATE DATABASE COMPLETED\n");
			        }
			        else
			        {
					printf("ERROR: CREATE DATABASE FAILED\n");
			        }
				break;
			case 2:
				if(cflag || uflag)
				{
					display_database(arr);
				}
				else
				{
					printf("ERROR: WITHOUT CREATE DATABASE OR UPDATE DATABASE CANNOT DISPLAY\n");
				}
				break;
		        case 3:
				if(cflag || uflag)
				{
					char str[20];
			                printf("Enter a word to search\n");
			                scanf("%s",str);
			                search_database(str,arr);
				}
				else
				{
					printf("ERROR: WITHOUT CREATE DATABASE OR UPDATE DATABASE CANNOT DISPLAY\n");
				}
			        break;
		        case 4:
				{
				char str2[20];
			        printf("Enter a file name\n");
			        scanf("%s",str2);

				char *ptr = strstr(str2,".");
				if(ptr != NULL && strcmp(ptr, ".txt") == 0)
			        {
					if(save_database(str2,arr)==SUCCESS)
					{
						printf("SAVE DATABASE COMPLETED\n");
					}
					else
					{
						printf("SAVE DATABASE FAILED\n");
					}
			        }
			        else
			        {
					printf("ERROR: FILE MUST BE .txt EXTENSION\n");
			        }
			        break;
				}
			case 5:
				if(cflag == 0 && uflag == 0)
				{
				        if(update_database(arr) == SUCCESS)
					{
						uflag = 1;
						printf("UPDATE DATABASE COMPLETED\n");
					}
					else
					{
						printf("UPDATE DATABASE FAILED\n");
					}

				}
				else
				{
					printf("ERROR: UPDATE DATABASE FAILED\n");
				}
				break;
			case 6:
				return 0;
		}
	}
	return 0;
}
