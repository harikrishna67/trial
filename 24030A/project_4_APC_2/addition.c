#include "main.h"
#include<stdio.h>

// Function to add two numbers represented by doubly linked lists

int addition(Dlist ** h1,Dlist ** t1,Dlist ** h2,Dlist ** t2,Dlist ** h3,Dlist ** t3) 
{
	int carry = 0,data;
    	Dlist * temp1 = *t1;	
	Dlist * temp2 = *t2;

	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 != NULL && temp2 != NULL)
		{	
			data = (temp1 -> data) + (temp2 ->data) + carry;
	 		temp1 = temp1 -> prev;
         		temp2 = temp2 -> prev;
		}
		else if(temp1 != NULL && temp2 == NULL)
		{
			data = (temp1 -> data) + carry;
			temp1 = temp1 -> prev;
		}
		else if (temp1 == NULL && temp2 != NULL)
		{
			data = (temp2 -> data) + carry;
                	temp2 = temp2 -> prev;
        	}
			
		if(data > 9)
		{
			update_result(h3,t3,(data%10));
			carry = 1;
		}
		else
		{
			update_result(h3,t3,data);
                	carry =0;
		}

	}
	if(carry != 0)
	{
        	update_result(h3, t3, carry);  // Handle leftover carry
        	carry = 0;
	}
    return SUCCESS;
}



