#include<stdio.h>
int main()
{
    int i,j,k,num;
    printf("Enter rows");
    scanf("%d",&num);
    for (i=num;i>=1;i--)
    {
        int p='A';
        for(j=1;j<=(i-1);j++)
        {
            printf(" ");
        }
        printf("%c",p++);
    }
    printf("\n");
}