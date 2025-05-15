#include<stdio.h>
int main()
{
    int a,b,c;
    printf("enter the sides:");
    scanf("%d%d%d", &a,&b, &c);
    if (a*a + b*b == c*c)
    {
        printf("its a right angle traingle");
    }
    else
    {
        printf("its not a right angle traingle");
    }
return 0;
}