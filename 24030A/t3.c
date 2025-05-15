#include<stdio.h>
int main()
{
    int a,b,c,n;
    scanf("%d%d%d", &a,&b,&c);
    n = a>b ?  a>c?a:c  :   b>c?b:c ;
    printf("Largest number is %d", n);
}