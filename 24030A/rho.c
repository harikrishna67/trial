#include<stdio.h>
int main()
{
    int rows,j,i,s;
    printf("enter the rows:");
    scanf("%d", &rows);
    for(int i=1;i<=rows;i++)
    {
       for(s=1;s<=rows-i;s++)
       {
        printf(" ");
       } 
        
        for(j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(i=rows-1;i>=1;i--)
    {
       for(int s=1;s<=rows-i;s++)
       {
        printf(" ");
       } 
        
        for(int j=1;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}