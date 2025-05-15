/*
	NAME : HARIKRISHNA P
	BATCH : 24030A
	DATE : 24/03/2025
	Project  :  APC (Arbitrary Precision Calculator)
	Description : The Arbitrary Precision Calculator (APC) is a powerful tool for performing arithmetic operations 
	on very large numbers with precision beyond the typical limits of standard data types. 
	This project demonstrates the implementation of fundamental arithmetic
	operations using **doubly linked lists** to handle numbers of arbitrary size.

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include "main.h"


// Head and tail for first number
	int delay = 50000; // Delay in microseconds (100ms)


Dlist * h1 = NULL;
Dlist * t1 = NULL;

// Head and tail for second number
Dlist * h2 = NULL;
Dlist * t2 = NULL;

// Head and tail for result
Dlist * h3 = NULL;
Dlist * t3 = NULL;

int main(int argc , char * argv[])
{
	system("clear");
	if(argc != 4 )
	{
		printf("ERROR : Provide input as <operand1> <operator> <operand2>");
		printf("INFO :  Eg -> %s 5 + 3\n",argv[0]);
		return 0;
	}
	if(strlen(argv[2]) != 1)
	{
		printf("ERROR : INVALID OPERATOR USED!!!\n");
		printf("INFO : OPERATORS ARE : + , - , X ");
		return 0;
	}
	
	int operand_1sign = 1;
	int operand_2sign = 1;

	if(argv[1][0] == '-') //if 1st operand is negative
	{
		operand_1sign = -1; //if the sign is -1
		argv[1]++; //skip the sign
	}

	if(argv[3][0] == '-') //if the second operand is negative
	{
		operand_2sign = -1; //if the sign is -1
		argv[3]++; //skip the sign
	}

	

	
	//Operand 1 (First Number):
	char * operand_1 = argv[1];
	if(store_operand(operand_1,&h1,&t1)== FAILURE)
	{
		return 0;
	}

	//Operator:
	char operator = argv[2][0];

	//Operand 2 (Second Number): 
	char * operand_2 = argv[3];
	//printf("oper1 1 : %s\n",operand_1);
    //printf("oper 2 : %s\n",operand_2);
	if(store_operand(operand_2,&h2,&t2)==FAILURE)
	{
		return 0;
	}

	char * neg_num = (operand_1sign == -1) ? (operand_1) : (operand_2);
	char * pos_num = (operand_1sign == -1) ? (operand_2) : (operand_1);

	//printf("%s\n",neg_num);
    //printf("%s\n",pos_num);

	
	
	//Operand 1 (First Number):
    
	if(operand_1sign == -1)
	{
		printf("-");
	}

    print_list(h1);

	printf(" %c ", operator);

	//Operand 2 (Second Number): 
	if(operand_2sign == -1)
	{
		printf("-");
	}
    print_list(h2);
	printf(" = ");

		switch(operator)
		{
			case '+' : 
				   //printf("\nINFO: Performing addition of the two operands.\n");
				    if(operand_1sign == operand_2sign)
					{
						addition(&h1,&t1,&h2,&t2,&h3,&t3);
						if(operand_1sign == -1)
						{
							printf("-");
						}
					}
					else
					{
						subtraction(&h1,&t1,&h2,&t2,&h3,&t3,argv);
						if(is_operand_larger(neg_num,pos_num) == SUCCESS)
						{
							printf("-");
						}
					}
				    break;
			case '-' :
				   if(operand_1sign ==  1 && operand_2sign == 1)
					{
						subtraction(&h1,&t1,&h2,&t2,&h3,&t3,argv);
						if((is_operand_larger(operand_1,operand_2))==FAILURE)
						{
							printf("-");
						}
						/*if(operand_1sign == -1)
						{
							if((is_operand_larger(neg_num,pos_num) == SUCCESS))
							{
								printf("-");
							}
						}*/
					}
					else if(operand_1sign == -1 && operand_2sign == -1)
					{
						subtraction(&h1,&t1,&h2,&t2,&h3,&t3,argv);
						/*if((is_operand_larger(operand_1,operand_2))==FAILURE)
						{
							printf("-");
						}*/
						if(operand_1sign == -1)
						{
							if((is_operand_larger(neg_num,pos_num) == SUCCESS))
							{
								printf("-");
							}
						}
					}
					else 
					{
						addition(&h1,&t1,&h2,&t2,&h3,&t3);
						if(operand_1sign == -1 && is_operand_larger(neg_num,pos_num) == SUCCESS)
						{
							printf("-");
						}
					}
				   
				   break;	
			case 'x' : 
					multiplication(&h1,&t1,&h2,&t2,&h3,&t3);
					if(operand_1sign != operand_2sign)
					{
						printf("-");
					}
					break;
			
			case '/' :
					division(&h1,&t1,&h2,&t2,&h3,&t3,argv,operator);
					if(operand_1sign != operand_2sign)
					{
						printf("-");
					}
					break;
			case '%' :
					division(&h1,&t1,&h2,&t2,&h3,&t3,argv,operator);
					break;
			default:
        			printf("ERROR: Unsupported operator '%c'.\n", operator);
        			return FAILURE;
		}
	print_list(h3);
}

	
