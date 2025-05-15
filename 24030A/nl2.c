#include<stdio.h>
int main()
{
    int num;
    printf("Enter max lines:");
    scanf("%d", &num);
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}