#include<stdio.h>
int main()
{
    int rows,cols;
    printf("Enter number of rows and columns");
    scanf("%d%d", &rows, &cols);
    int arr[rows][cols];


    printf("enter the elemenets\n");
    for(int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }

    }
    printf("array elements are:\n");
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}