#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);


    int **array = (int **)malloc(rows * sizeof(int *));
    
    
    for (int i = 0; i < rows; i++) 
    {
        array[i] = (int *)malloc(cols * sizeof(int));    
    }


    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            array[i][j] = i * j; 
        }
    }
    printf("Enter the Elements:");
     for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &array[i][j]);
        }
    }

    printf("The 2D array is:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < rows; i++) 
    {
        free(array[i]);
    }
    free(array);

    return 0;
}
