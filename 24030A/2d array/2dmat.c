#include<stdio.h>
#include<stdlib.h>
int **allocate_memory(int , int );
void read(int **, int, int);
void multiplyMatrices(int **, int **, int **, int , int , int , int);
void displayMatrix(int **, int , int ); 

int main() 
{
    int rowsA, colsA, rowsB, colsB;


    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);


if (colsA != rowsB) 
{
    printf("Matrix multiplication is not possible.\n");
    return 1;
} 
int **A = allocate_memory(rowsA,colsA);
int **B = allocate_memory(rowsB,colsB);
int **res = allocate_memory(rowsA,colsA);

    inputMatrix(A, rowsA, );
    inputMatrix(B, rowsB, colsB);

    
    multiplyMatrices(A, B, C, rowsA, colsA, rowsB, colsB);

    
    displayMatrix(C, rowsA, colsB);

}
int** allocate_memory(int rows, int cols) 
{

    int **A = (int **)malloc(rows * sizeof(int *));
    
   

    for (int i = 0; i < rows; i++) 
    {
        A[i] = (int *)malloc(cols * sizeof(int));
    }
    return A;
}
void inputMatrix(int **matrix, int rows, int cols, char name) 
{
    printf("Enter elements of matrix %c (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("Enter element %c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void multiplyMatrices(int **A, int **B, int **C, int rowsA, int colsA, int rowsB, int colsB) 
{

    for (int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < colsB; j++) 
        {
           C[i][j] = 0;
        
            for (int k = 0; k < colsA; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void displayMatrix(int **matrix, int rows, int cols) 
{
    printf("\nResulting Matrix C (A * B):\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}






