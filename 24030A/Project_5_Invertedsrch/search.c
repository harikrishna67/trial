#include "inverted_search.h"

int search( Wlist *head, char *word)
{
    //check list empty or not

    if(head == NULL)
    {
		printf("There is no word starting with '%c'\n",word[0]);
		return 1;
    }

    //traverse through the list

    while(head)
    {
	//Compare the search word with available words in a list
		if(!strcmp(head->word , word))
		{
	    	printf("Word %s is present in %d file/s \n" , word , head->file_count);

	    	Ltable *Thead = head->Tlink;
	    	while(Thead)
	    	{
				printf("In file : %s   %d  time\n" , Thead->file_name , Thead->word_count);
				Thead = Thead->table_link;
	    	}
	    	printf("\n");
	    	return 0;
		}

		head = head->link;
    }
    printf("Search word is not present in the list\n");
}

