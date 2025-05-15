#include "main.h"

int print_list(Slist *head)
{
    Slist *temp = head;
    while (temp != NULL)
    {
        printf("%d \n",temp->data);
        printf("\n");
        temp = temp->link;
    }
    return SUCCESS;
    
}