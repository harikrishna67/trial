#include "main.h"
#include<stdio.h>
#include<string.h>

// Function to subtract two numbers represented by doubly linked lists
int subtraction(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3,char * argv[])
{
    // Check and swap lists if necessary to ensure first number is larger
    check_and_swap(h1, t1, h2, t2, argv);
    

    // Perform the subtraction operation
    perform_subtraction(h1,t1,h2,t2,h3,t3);
    return SUCCESS;
    
}

// Function to perform subtraction on two doubly linked lists
int perform_subtraction(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3)
{
    // Pointer to traverse the first operand and second operand
    Dlist * temp1 = *t1;	
    Dlist * temp2 = *t2;

    // Borrow flag to handle cases when num1 < num2
    int borrow = 0;
    int data =0,num1,num2;

    // Iterate through both lists until both are fully traversed
    while(temp1 != NULL)
    {
        num1 = temp1 -> data; // Get the current digit from the first number	
        num2 = (temp2 != NULL) ? temp2->data : 0; // Get the current digit from the second number(if second digit is shoter then default 0)

        // Adjust num1 if there was a previous borrow
        if(borrow == 1)
        {
            num1 = num1 - 1;
	        borrow = 0; //reset the borror flag
        }

        //if num=1 < num2 , we need to borrow
        if(num1 < num2 )
        {
            borrow = 1; //set borrorw flag for next dif=git 
            num1 = num1 + 10; // add 10 to num1
        }

            // Perform subtraction for the current digit and store the result
            data  = num1 - num2;
            update_result(h3,t3,data);

       
        // Move to the previous digits
        temp1 = temp1 -> prev;
        if (temp2 != NULL)
            temp2 = temp2->prev;
    }

    // Now remove leading zeros by deleting them from the head of the result list
    while (*h3 != NULL && (*h3)->data == 0)
    {
        // Call dl_delete_first to delete the leading zero node
        dl_delete_first(h3, t3); // Remove the first node (which is zero)
        //*h3 = (*h3)->next;
    }

    // If the list is empty after removing zeros, set the tail to NULL as well
    if (*h3 == NULL)
    {
        *t3 = NULL;
    }

     return SUCCESS;
}
