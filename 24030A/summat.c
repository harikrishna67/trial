#include<stdio.h>
int main()
{
    int rows,col,i,j;
    printf("enter the number of rows:");
    scanf("%d", &rows);
    printf("enter the number of col:");
    scanf("%d", &col);

    int mat1[100][100], mat2[100][100], sum[100][100];
    printf("enter mtrix one:\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("enter mtrix two:\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("sum is:\n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}
// #include <stdio.h>

// int main() {
//     int rows, cols, i, j;

//     // Input size of the matrices
//     printf("Enter number of rows: ");
//     scanf("%d", &rows);
//     printf("Enter number of columns: ");
//     scanf("%d", &cols);

//     int matrix1[100][100], matrix2[100][100], sum[100][100];

//     // Input elements of matrix 1
//     printf("Enter elements of first matrix:\n");
//     for (i = 0; i < rows; i++) {
//         for (j = 0; j < cols; j++) {
//             scanf("%d", &matrix1[i][j]);
//         }
//     }

//     // Input elements of matrix 2
//     printf("Enter elements of second matrix:\n");
//     for (i = 0; i < rows; i++) {
//         for (j = 0; j < cols; j++) {
//             scanf("%d", &matrix2[i][j]);
//         }
//     }

//     // Adding matrices
//     for (i = 0; i < rows; i++) {
//         for (j = 0; j < cols; j++) {
//             sum[i][j] = matrix1[i][j] + matrix2[i][j];
//         }
//     }

//     // Display result
//     printf("Sum of the two matrices:\n");
//     for (i = 0; i < rows; i++) {
//         for (j = 0; j < cols; j++) {
//             printf("%d ", sum[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }
