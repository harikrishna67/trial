#include "main.h"
#include<stdio.h>

int multiplication(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3)
{
    // Head and tail for intermediate result
    Dlist * h_res1 = NULL;
    Dlist * t_res1 = NULL;

    // Head and tail for accumulated result
    Dlist * h_res2 = NULL;
    Dlist * t_res2 = NULL;
    insert_at_last(&h_res2,&t_res2,0); // Initialize accumulated result to 0

    // Final result
    Dlist * h_res3 = NULL;
    Dlist * t_res3 = NULL;
    
    Dlist * temp1 = *t1;
    Dlist * temp2 = *t2;
    int carry=0,data =0,num1,num2,iter=0;

    // Multiply each digit of temp1 with the current digit of temp2
    while(temp2 != NULL)
    {
        carry=0;

        //shift the intermediate result by adding zeros based on the iteration
        for(int i=0;i<iter;i++)
        {
            insert_at_last(&h_res1,&t_res1,0);
        }

        //multiply each digit of temp1 with current digit of temp2
        while(temp1 != NULL)
        {
            num1 = temp1->data;
            num2 = temp2->data;
            data = (num1 * num2 ) + carry;

            //handle carry
            if(data >9)
            {
                update_result(&h_res1,&t_res1,(data%10)); // Store the last digit
                carry = data/10; // Update carry
            }
            else
            {
                update_result(&h_res1,&t_res1,(data));
                carry = 0; // Reset carry
            }
            temp1 = temp1->prev; // Move to the previous digit in temp1
        }
        // If there is any carry left after processing temp1, add it to the result
        if (carry > 0)
        {
            update_result(&h_res1, &t_res1, carry);
        }
        
        // Add the intermediate result (h_res1) to the accumulated result (h_res2)
        addition(&h_res1,&t_res1,&h_res2,&t_res2,&h_res3,&t_res3);

        // Move to the next digit in temp2 and reset temp1
        temp2 = temp2->prev;
        temp1 = *t1;

        iter++; // Increment iteration counter for the next positional shift

        // If temp2 is null, print the final result and exit
        if(temp2 == NULL)
        {
            //print_list(h_res3);
            *h3 = h_res3;
            *t3 = t_res3;
            return SUCCESS;
        }
        
        //update the accumulated result
        h_res2 = h_res3;
        t_res2 = t_res3;

        // Reset the result list for the next multiplication
        h_res3 = NULL;
        t_res3 = NULL;

        dl_delete_list(&h_res1,&t_res1); // Clean up the intermediate result list

        if (h_res1 != NULL || t_res1 != NULL) 
        {
            printf("Error: h_res1 and t_res1 not cleared properly.\n");
        }
        h_res1 = NULL;
        t_res1 = NULL;
    }
    
    // Set the final result
    *h3 = h_res2;
    *t3 = t_res2;
    return SUCCESS;
}
