#include "invert.h"

int insert_at_last(Slist **head, char data[])
{
        Slist *new,*temp;
        new = malloc(sizeof(Slist));
        if(new == NULL)
                return FAILURE;

    strcpy(new->data,data);
    new -> link = NULL;

    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
	    temp = *head;
	    while(temp->link != NULL)
	    {
		    temp = temp->link;
	    }
	    temp->link = new;
    }
    return SUCCESS;
}
