#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter n:");
    scanf("%d", &n);
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j>=n-(i-1) && j<=n+(i-1))
            {
                printf(" ");
            }
            else
            {
                printf("%d ",j);
            }
        }
        printf("\n");
    }
}