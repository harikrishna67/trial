#include<stdio.h>
int main()
{
    int num,i,count=0;
    scanf("%d",&num);
    for(i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            count=1;
            break;
        }}
if(count==0)
        {
            printf("prime\n");
        }
        else
        {
            printf("composite\n");

        }
    }
