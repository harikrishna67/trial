#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1
#include<stdio.h>


// Define the structure for a doubly linked list node
typedef struct Dlist
{
	struct Dlist * prev;
	int data;
	struct Dlist * next;
}Dlist;

// Function prototypes

// Prints all elements of the doubly linked list
void print_list(Dlist *head);

void print_with_delay(const char *str, int delay);

void draw_boxed_calculator();

// Stores a numeric operand as a linked list
int store_operand(char * operand , Dlist ** h ,Dlist ** t);

int is_operand_larger(char * neg_num , char * pos_num);

// Inserts a new node at the end of the doubly linked list
int insert_at_last(Dlist ** head , Dlist ** tail , int data);

// Updates the result list by appending a new node with the given data
int update_result(Dlist ** head , Dlist ** tail , int data);

// Swaps two doubly linked lists (pointers to their heads and tails)
//void swap_lists(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2);
void swap_lists(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2);

// Returns the length of a given string
int get_length(const char *str);

int get_list_length(Dlist *temp);

// Checks and swaps lists if necessary based on certain conditions
int check_and_swap(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, char *argv[]);

// Validates operands and assigns them to linked lists
int check_and_assign(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,char *argv[]);

// Deletes the entire doubly linked list
int dl_delete_list(Dlist **head, Dlist **tail);

int dl_delete_first(Dlist **head, Dlist **tail);

// Converts a linked list representing a number into an integer
//int listToInt(Dlist * head);

// Compares two linked lists (numerically) to determine equality
int compare_lists(Dlist *h_res, Dlist *t_res, Dlist *h2 , Dlist *t2 );

// Performs addition of two numbers represented as linked lists
int addition(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3);

// Performs subtraction of two numbers represented as linked lists
int subtraction(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3,char * argv[]);

// Helper function to perform the actual subtraction operation
int perform_subtraction(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3);

// Performs multiplication of two numbers represented as linked lists
int multiplication(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3);

// Performs division or modulo operation on two numbers represented as linked lists
int division(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3,char *argv[],char operator);

// Helper function to perform the actual division operation
int perform_division(Dlist ** h_res,Dlist ** t_res,Dlist ** h_div,Dlist ** t_div,Dlist * temp,Dlist** h2,Dlist** t2,Dlist ** h3,Dlist** t3,char * argv[]);

#endif
