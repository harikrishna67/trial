#include<stdio.h>
int main()
{
    int num,f=0,s=1,n=0;
    printf("enter the number:");
    scanf("%d", &num);
    if(num <0)
    {
        printf("invalid");
    }
    else
    {
        printf("%d ", f);
        while(s<=num)
        {
            printf("%d ", s);
            n = f+s;
            f = s;
            s = n;

        }
    }
}