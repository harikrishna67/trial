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
    printf("array elements are:");
    for (int i=0;i<rows;i++)
    {
            int sum =0;
        for (int j=0;j<cols;j++)
        {
            sum = sum + arr[i][j];
        }
    float avg = (float) sum / cols;
    printf("Avg(%d) is %g\n", i+1,avg);
    }
    return 0;
}