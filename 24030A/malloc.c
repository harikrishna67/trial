#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size;
    int *arr = (int *)malloc(size * sizeof(int));
    printf("enter element:");
    scanf("%d", &size);
    for(int i = 0; i<size; i++)
    {
        scanf("%d", arr + i);

    }
    printf("Output: \n");
    for(int i=0;i<size;i++)
    {
        printf("%d", arr[i]);

    }
    printf("\n");
    free(arr);
    for(int i=0;i<size;i++)
    {
        printf("%d", arr[i]);

    }

}