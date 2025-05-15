#include "sll.h"

int find_node(Slist *head, data_t data)
{
    if(head==NULL)
    {
        return FAILURE;
    }
    Slist *temp = head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        if(temp->data==data)
        {
            return count;
        }
        temp=temp->link;
    }
    return FAILURE;
	
}
