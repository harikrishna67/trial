#include "inverted_search.h"

int save_database( Wlist *head[])
{
    //prompt the user to enter a file name to save the database

    char file_name[FNAME_SIZE];

    printf("Enter the file name\n");
    scanf("%s", file_name);

    //open file 

    FILE *fptr= fopen(file_name , "w");
    if (fptr == NULL)
    {
	printf("Failed to open file.\n");
	return FAILURE;;
    }

    for(int i = 0 ; i < 27 ; i++)
    {
	if(head[i] != NULL)
	{
	    write_databasefile(head[i] , fptr);
	}
    }
    printf("\033[1;32mSuccess: Database is saved to %s\033[0m\n",file_name);
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    while( head != NULL )
    {
	fprintf(databasefile, "#[%d]\n", (tolower(head->word[0]))%97 );
	fprintf(databasefile, "word is [%s]: file count is %d\n", head->word, head->file_count);
	Ltable *temp = head->Tlink;
	while( temp != NULL )
	{
	    fprintf(databasefile, "file is %s: word count is %d\n", temp->file_name, temp->word_count);
	    temp = temp->table_link;
	}
	printf("\n");
	head = head->link;
    }
}

