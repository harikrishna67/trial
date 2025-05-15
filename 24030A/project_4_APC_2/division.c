#include "main.h"
#include<stdio.h>

int perform_division(Dlist ** h_res,Dlist ** t_res,Dlist ** h_div,Dlist ** t_div,Dlist *temp,Dlist ** h2,Dlist** t2,Dlist ** h3,Dlist** t3,char * argv[])
{

    int count =0;  // To count how many times subtraction is performed
    static int i=0; // Static variable to track if a zero should be added during the division

    // Copy elements from the numerator list (temp) to result list (h_res) and handle zeros if necessary
    while(temp != NULL && (compare_lists(*h_res,*t_res,*h2,*t2) == SUCCESS))
    {
        while (*h_res != NULL && (*h_res)->data == 0)
        {
        // Call dl_delete_first to delete the leading zero node
            dl_delete_first(h_res, t_res); // Remove the first node (which is zero)
            //h_res = (h_res)->next;
        }
         insert_at_last(h_res,t_res,(temp->data)); // Add data from temp to result list
         temp = temp->next;
         if(i != 0)
        {
            insert_at_last(h_div,t_div,0); // Add zero to division list after the first digit
            //printf("added zero \n");
        }
    }

    /*printf("\npresent num to get divide : ");
    print_list(*h_res);
    printf("\n");*/
    

    // Perform the division by repeatedly subtracting the divisor (h2) from the numerator (h_res)
    while((compare_lists(*h_res,*t_res,*h2,*t2) == FAILURE))
    {
        perform_subtraction(h_res,t_res,h2,t2,h3,t3); // Subtract the divisor from the numerator
        count++; // Increment count (each subtraction corresponds to a division step)
    
        // Update result and temp lists for next operation
        *h_res = *h3;
        *t_res = *t3;

        // Reset the intermediate list
        *h3 = NULL; 
        *t3 = NULL;
        
    }

        insert_at_last(h_div, t_div, count); // Add the quotient to the division list
        count = 0; // Reset count for the next digit

        // If temp is not NULL and the division is complete, move to the next digit in the numerator
        if(temp != NULL && (compare_lists(*h_res,*t_res,*h2,*t2) == SUCCESS))
        {
           insert_at_last(h_res,t_res,temp->data); // Add the next digit to the result
           temp = temp->next;  

            i = i+1;  // Increment the index to handle the next digit
            perform_division(h_res, t_res, h_div, t_div,temp,h2, t2, h3, t3,argv); // Recursively continue division
        }
}

// Main function for division, initializing required lists
int division(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3,char *argv[],char operator)
{
    if(check_and_assign(h1, t1, h2, t2,argv) == SUCCESS)
    {
        return SUCCESS;
    }
    
    //create a reult list
    Dlist * h_res = NULL;
    Dlist * t_res = NULL;

    Dlist * temp = *h1; // Copy of the numerator list

    // Create a result list for the quotient
    Dlist * h_div = NULL;
    Dlist * t_div = NULL;

    perform_division(&h_res,&t_res,&h_div,&t_div,temp,h2,t2,h3,t3,argv);
    if (operator == '/')
     {
        //printf("\n\nRESULT (Division): ");
        //print_list(h_div);  // Print the quotient
        *h3 = h_div;
        *t3 = t_div;
    }
    else if (operator == '%')
    {
        //printf("RESULT (Modulo): ");
        //print_list(h_res);  // Print the remainder
        *h3 = h_res;
        *t3 = t_res;
    } 
    return SUCCESS; 
 }


