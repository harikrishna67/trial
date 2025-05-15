#include<stdio.h>
int main()
{
    int num1;
    {
        printf("enter a number:");
        scanf("%d", &num1);
    }
        if(num1 % 2)
    {
            printf("number is even\n");
    }
    else 
    {
        printf("number is odd\n");
    }

    return 0;
}