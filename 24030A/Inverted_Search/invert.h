#ifndef INVERT_H
#define INVERT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
        char data[20];
        struct node *link;
}Slist;

typedef struct hash
{
	int index;
	struct main_node *hlink;
}hash_t;

typedef struct main_node
{
	int fcount;
	char word[30];
	struct sub_node *slink;
	struct main_node *mlink;
}Main;

typedef struct sub_node
{
	int wcount;
	char file[20];
	struct sub_node *nslink;
}Sub;

int read_validate(int argc, char *argv[], Slist **head);
int insert_at_last(Slist **head, char data[]);
int create_database(hash_t arr[], Slist **head);
int display_database(hash_t arr[]);
int search_database(char str[],hash_t arr[]);
int save_database(char str2[],hash_t arr[]);
int update_database(hash_t arr[]);
void print_list(Slist *head);
#endif
