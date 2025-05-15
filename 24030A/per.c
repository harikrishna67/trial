#include<stdio.h>
int main()
{
    int num,rev =0;
    printf("Enter a number:");
    scanf("%d", &num);
    if(num<0)
    {
        printf("Invalid number");
    }
    else
    {
        while(num)
        {
            rev = rev *10;
            rev = rev + num % 10;
            num = num / 10;
        }
        printf("Reversed number is:%d\n", rev);
        return 0;

    }
}