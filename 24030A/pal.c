#include<stdio.h>
int main()
{
    int num,rev =0;
    printf("enter the number:");
    scanf("%d", &num);
    int a = num;
    if(num<0)
    {
        printf("noooooo");
    }
    else
    {
        while(num)
        {
            rev = rev * 10 + num % 10;
            num = num /10;
        }
        if(rev == a)
        {
            printf("pal");
        }
        else
        {
            printf("nooooppppppppppppp");
        }
    }

}