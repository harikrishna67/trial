#include<stdio.h>
int main()
{
    int i;
    for(i=0;i<=7;i++)
    {
        if(i==5)
        {
            continue;
        }
        printf("%d\n",i);
    }
}