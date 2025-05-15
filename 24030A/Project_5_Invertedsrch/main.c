/*
	NAME : HARIKRISHNA P
	BATCH : 24030A
	DATE : 24/03/2025
	DISCRIPTION : INVERTED SEARCH (The executable file is ./invertedsearch.exe)
*/

#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");
    Wlist *head[27] = {NULL};

    //validate
    if(argc <= 1)
    {
	printf("\033[1;31mERROR : Enter the valid no. arguments\n");
	printf("USAGE : ./Slist.exe file1.txt file2.txt.......\033[0m\n");
	return 0;
    }

    //create the file linked list
    //declare head pointer
    Flist *f_head = NULL;

    //validate the file
    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)
    {
	printf("\033[1;31mERROR : No files are available in the file linked list\n");
	printf("Hence the process terminated\033[0m\n");
	return 1;
    }
    char ch;
    do
    {
	printf("Select your choice among following optiions:\n1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter your choice:");
	int choice;
	char word[WORD_SIZE];
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
		create_database(f_head , head);
		break;
	    case 2 :
		display_database(head);
		break;
	    case 3 :
		update_database(head, &f_head);
		break;
	    case 4 :
		printf("Enter the word to search\n");
		scanf("%s" , word);
		search(head[tolower(word[0]) % 97] , word);
		break;
	    case 5 :
		save_database(head);
		break;
	    default :printf("Invalid choice\n");
	}
	printf("Do you want to continue ? (y/Y - Yes n/N - No):");
	scanf(" %c", &ch);
    }while( ch == 'y' || ch == 'Y' );
}
