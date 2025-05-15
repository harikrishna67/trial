#include "inverted_search.h"
void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through file list
    while(f_head)
    {
	read_datafile(f_head , head , f_head->file_name);
	printf("\033[1;32mSuccessfully updated data base for the file %s\033[0m\n", f_head -> file_name);
	f_head = f_head->link;
    }

}

//read contents of file
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
    int flag = 1;
    strcpy(f_name, filename);

    FILE *fptr = fopen(filename , "r");

    //declare an array to store the words
    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	flag = 1;

	//making the index association case insensitive
	int index = tolower(word[0]) % 97;

	//If the fiest letter is not an alphabet make the index as 26
	if(!(index >= 0 && index <= 25))
	{
	    index = 26;
	}

	//check whether words are repeated or not
	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];
	    while(temp)
	    {
		if(!strcmp(temp->word , word))
		{
		    update_word_count(&temp , filename);
		    flag = 0;
		    break;
		}
		temp = temp->link;
	    }
	}
	//If word are not repeated call insert_at_last function
	if (flag == 1)
	{
	    insert_at_last(&head[index] , word);
	}
    }
}


int update_word_count(Wlist ** head, char * file_name)
{
    //checkinf if the filename is same or not
    if (!strcmp(((*head)->Tlink)->file_name, file_name ))
    {
	//if it is same increment word_count
	( ((*head)->Tlink)->word_count)++;
    }
    else
    {
	//if not increment file_count
	((*head)->file_count )++;
	//create Ltable node
	Ltable *new = malloc(sizeof(Ltable));
	if (new == NULL)
	{
	    return FAILURE;
	}
	new -> word_count = 1;
	strcpy(new -> file_name , file_name);
	new -> table_link = NULL;
	((*head)->Tlink) -> table_link = new;
    }
}
