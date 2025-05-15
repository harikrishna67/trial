#include<stdio.h>
#include "main.h"
#include<stdlib.h>
#include <unistd.h>
#include <string.h>
// Function to store operands in a doubly linked list
int store_operand(char * operand , Dlist ** h ,Dlist ** t)
{
     int i=0;
	 while(operand[i] != '\0')
	 {
        // Validate that each character is a digit between '0' and '9'
        if(operand[i] < '0' || operand[i] > '9')
        {
            printf("ERROR: Invalid character '%c'. Only digits between '0' and '9' are allowed.", operand[i]);
    
            return FAILURE;  // Exit the function if invalid character is found
        }
		 insert_at_last(h,t,(operand[i]-'0'));
          i++;
	 }
}



        
// Function to insert a new node at the end of the list
int insert_at_last(Dlist **head ,Dlist ** tail , int data)
{
	Dlist * new = malloc(sizeof(Dlist));
	if(new == NULL)
	{
        printf("ERROR: Memory allocation failed while inserting data.\n");
		return FAILURE;
	}
	new->prev = NULL;
    	new->data = data;
    	new->next = NULL;

	if(*head == NULL)
	{
		*head = new;
		*tail = new;
		return SUCCESS;
	}
	new -> prev = *tail;
	(*tail) -> next = new;
	(*tail) = new;
	return SUCCESS;
}



// Function to print the list
void print_list(Dlist *head)
{
	/* Cheking the list is empty or not 
	if (head == NULL)
	{
		printf(" 0 ");
	}*/

    while (head != NULL && head->data == 0)
    {
        head = head->next;
    }

	// If we skipped all elements, the list represents "0"
    if (head == NULL)
    {
        printf("0");
        return;
    }

     // Print remaining elements
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
	       
}



// Function to update the result linked list
int update_result(Dlist ** head , Dlist ** tail , int data)
{
    Dlist * new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        printf("ERROR: Memory allocation failed while inserting data.\n");
        return FAILURE;
    }
    new->prev = NULL;
    new->data = data;
    new ->next = NULL;

    if(*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head=new;
    }
    return SUCCESS;
}

//function to swap the list
void swap_lists(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2)
{
    //update the heads
    Dlist *temp_head = *h1;
    *h1 = *h2;
    *h2 = temp_head;

    //update the tails
    Dlist *temp_tail = *t1;
    *t1 = *t2;
    *t2 = temp_tail;
}

// Function to calculate the length of a string
int get_length(const char *str) 
{
    return strlen(str);
}


//function to check and swap two lists if necessary
int check_and_swap(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2, char *argv[]) 
{
    int len1 = get_length(argv[1]);
    int len2 = get_length(argv[3]);

    // Swap lists if the first number is less than the second or
    //if both numbers are of equal length but the first is less than the second, swap the lists
    if (len1 < len2 || (len1 == len2 && strcmp(argv[1], argv[3]) < 0)) 
	{
        swap_lists(h1, t1, h2, t2);
    }
}

int is_operand_larger(char * neg_num , char * pos_num)
{
    int len1 = get_length(neg_num);
    int len2 = get_length(pos_num);

    if (len1 > len2 || (len1 == len2 && strcmp(neg_num,pos_num) > 0)) 
	{
        return SUCCESS;
    }
    return FAILURE;
}



int check_and_assign(Dlist **h1, Dlist **t1, Dlist **h2, Dlist **t2,char *argv[]) 
{
	int len1 = get_length(argv[1]);
    int len2 = get_length(argv[3]);
    // Swap lists if the first number is less than the second
    if (len1 < len2 || (len1 == len2 && strcmp(argv[1], argv[3]) < 0)) 
	{
		printf("RESULT : 0\n");
        return SUCCESS;
	}

    // If both numbers are equal, print "1"
	if((len1 == len2 && strcmp(argv[1], argv[3]) == 0))
	{
		printf("RESULT : 1\n");
        return SUCCESS;
	}
    return FAILURE;
}




int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL) //IF LIST IS EMPTY
    {
        return FAILURE;
    }
    //If list is not empty 
    Dlist *temp = *head; //Take temporary variable to delete first node
    while(temp != NULL) //traverse through each node till last node
    {
        *head = temp->next; // make head points to next node
        free(temp); //free the current node
        temp = *head; // make temp points to next node
    }
    
    //after deletion make head and tail as NULL6
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

int dl_delete_first(Dlist **head, Dlist **tail)
{
    if(*head == NULL) //if the list is empty
    {
        return FAILURE;
    }
    
    //if list is not empty 
    Dlist * temp = *head; //take temporary variable to delete first node
    if(*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = (*head)->next; //update the head points to the 2nd node
        (*head)->prev = NULL; //make 2nd node previous link part as NULL
    }
    free(temp); // Free the memory of the deleted node
     return SUCCESS;
}


int compare_lists(Dlist *h_res, Dlist *t_res, Dlist *h2 , Dlist *t2 )
{
    
    // Get the lengths of both lists
    int len1 = get_list_length(h_res);
    int len2 = get_list_length(h2);

    // Compare lengths first
    if (len1 < len2)
    {
        return SUCCESS; // h_res < h2
    }
    else if (len1 > len2)
    {
        return FAILURE; // h_res > h2
    }

    // If lengths are equal, compare digit by digit
    while (h_res != NULL && h2 != NULL)
    {
        if (h_res->data < h2->data)
        {
            return SUCCESS; // h_res < h2
        }
        else if (h_res->data > h2->data)
        {
            return FAILURE; // h_res > h2
        }

        // Move to the next digits
        h_res = h_res->next;
        h2 = h2->next;
    }

    // If all digits are equal, the lists are "equal" numerically
    return FAILURE; // Equal case (treated as not less than)
}

int get_list_length(Dlist *temp)
{
    int len = 0;

    // Traverse the list to count the nodes
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}





void print_with_delay(const char *str, int delay) 
{
    while (*str) {
        putchar(*str);     // Print one character
        fflush(stdout);    // Force the output to appear immediately
        usleep(delay);     // Wait for the specified delay (in microseconds)
        str++;             // Move to the next character
    }
}


