#include<stdio.h>
int main()
{
    int size;
    printf("enter the size");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements:");
    for (int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);

    }
    for (int i=0;i<size/2;i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("after reverzing are:");
    for (int i=0;i<size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

}