#include "inverted_search.h"

 int insert_at_last(Wlist **head, data_t *data)
{
    //create node
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
    {
		return FAILURE;
    }

    //update
    new->file_count = 1;
    strcpy(new->word ,data);
    new->Tlink = NULL;
    new->link = NULL;

    //call fun to update link table
    update_link_table(&new);

    //check list empty or not
    if(*head == NULL)
    {
		*head = new;
		return SUCCESS;
    }

    //traverse through the list
    Wlist *temp = *head;
    while(temp->link)
    {
		temp=temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    //create node
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
    {
		return FAILURE;
    }
    //update
    new->word_count = 1;
    strcpy(new->file_name, f_name);  
    new->table_link = NULL;

    (*head)->Tlink = new;

    return SUCCESS;
}
