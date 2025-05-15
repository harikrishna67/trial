#include <stdio.h>

int main() 
{
    int n;

    printf("Enter the size of matrix (n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }


    printf("\nX pattern diagonals:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j || i + j == n - 1) 
            {
                printf("%d ", matrix[i][j]);
            } 
            else 
            {
                printf("  "); 
            }
        }
        printf("\n");
    }

    return 0;
}
