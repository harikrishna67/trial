#include<stdio.h>
int main()
{
    int rows,cols, sum=0;
    printf("Enter number of rows and columns");
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
    printf("array elements are:");
    for (int i=0;i<rows;i++)
    {
        for (int j=0;j<cols;j++)
        {
            sum = sum + arr[i][j];
        }
    }
    float avg = (float)sum/ (rows * cols);
    printf("Avg is %f", avg);
    return 0;
}