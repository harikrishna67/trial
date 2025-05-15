#include<stdio.h>
int main()
{
    int num1,num2,num3,max;
    printf("enter a number:");
    scanf("%d", &num1);
    printf("enter the 2nd number:");
    scanf("%d", &num2);
    printf("enter the 3rd num:");
    scanf("%d", &num3);

    if(num1>num2)
    {
        if(num1>num3)
        {
            max = num1;
            printf("%d is the greatest number",num1);
        }
        else
        {
             max = num3;
             printf("%d is the greatest number",num3);
        }
    else
        {
           if(num2>num3)
           max = num2;
           printf("%d is the greatest number",num2);  

        }
        else
        {
          printf("%d is the largest", num3);
        }
    }
    return 0;
}
