#include "inverted_search.h"

void display_database( Wlist *head[] )
{
    /*printf("[index]    [word]     file_count file/s   File: File_name    word_count\n");

    for(int i=0; i<27; i++)
    {
	if(head[i] != NULL)
	{
	    print_word_count(head[i]);
	}
    }*/
    printf("%-12s %-12s %-12s %-12s %-12s \n", "[index]", "[word]", "file-count", "file-name", "word-count");

    for(int i=0; i<27; i++)
    {
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}

 int print_word_count(Wlist *head)
{
    //traverse through the WList
    /*while(head != NULL)
    {
	printf("[%d]   [%s]    %d file/s : " , tolower(head->word[0]) % 97 , head->word , head->file_count);

	Ltable *Thead = head->Tlink;
	//traverse
	while(Thead)
	{
	    printf("File : %s   %d ", Thead->file_name , Thead->word_count);
	    Thead = Thead->table_link;
	}
	printf("\n");

	head = head->link;
    }*/
    while(head != NULL)
    {

        Ltable *Thead = head->Tlink;

        //traverse
        while(Thead)
        {
            printf("%-12d %-12s %-12d " , tolower(head->word[0])%97, head->word, head->file_count);
            printf("%-12s %-12d\n", Thead->file_name , Thead->word_count);
            Thead = Thead->table_link;
        }
        printf("\n");

        head = head->link;
    }
}





