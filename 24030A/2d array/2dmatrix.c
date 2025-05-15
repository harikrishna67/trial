#include <stdio.h>
#include <stdlib.h>

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

void multiplyMatrices(int **A, int **B, int **C, int rowsA, int colsA, int rowsB, int colsB) {

    for (int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < colsB; j++) 
        {
        
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

void freeMatrix(int **matrix, int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main() 
{
    int rowsA, colsA, rowsB, colsB;


    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    


    int **A = malloc(rowsA * sizeof(int *));
    int **B = malloc(rowsB * sizeof(int *));
    int **C = malloc(rowsA * sizeof(int *));
    
    for (int i = 0; i < rowsA; i++) 
    {
        A[i] = malloc(colsA * sizeof(int));
    }

    for (int i = 0; i < rowsB; i++) 
    {
        B[i] = malloc(colsB * sizeof(int));
    }

    for (int i = 0; i < rowsA; i++) 
    {
        C[i] = malloc(colsB * sizeof(int));
    }
    inputMatrix(A, rowsA, colsA);
    inputMatrix(B, rowsB, colsB);

    
    multiplyMatrices(A, B, C, rowsA, colsA, rowsB, colsB);

    
    displayMatrix(C, rowsA, colsB);

    
    freeMatrix(A, rowsA);
    freeMatrix(B, rowsB);
    freeMatrix(C, rowsA);

    return 0;
}



