#ifndef SLL_H
#define SLL_H

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    int data;
    struct node *link;
}Slist;

int insert_at_last(Slist **head,int data);
int print_list(Slist *head);

#endif