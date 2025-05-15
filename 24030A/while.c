#include<stdio.h>
int main()
{
    int num,sum=0,rev;
    scanf("%d", &num);
    while(num>0)
    {
        rev=num%10;
        sum=sum*10+rev;
        num=num/10;
    }
    printf("the reverse number is %d\n",sum);
    
}    
