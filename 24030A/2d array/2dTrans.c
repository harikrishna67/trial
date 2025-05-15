#include<stdio.h>
int main()
{
    int rows,cols;
    printf("Enter number of rows and columns:\n");
    scanf("%d%d", &rows, &cols);
    int arr[rows][cols];


    printf("enter the elemenets");
    for(int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            scanf("%d", &arr[i][j]);
        }

    }
    printf("printed elements are:");
     for(int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
    printf("reversed elements are:");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows;j++)
        {
            int temp = arr[i][rows];
            arr[i][rows] = arr[i][cols];
            arr[i][cols] = temp;
        }
        rows++;
        cols--;
    }