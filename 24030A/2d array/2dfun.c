#include <stdio.h>
#include <stdlib.h>

void print2DArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) 
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            arr[i][j] = i * j; 
        }
    }

    print2DArray(arr, rows, cols);

    for (int i = 0; i < rows; i++) 
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
