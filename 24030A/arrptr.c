#include <stdio.h>

int main() 
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int* ptrArr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        ptrArr[i] = &arr[i]; 
    } 

    for (int i = 0; i < n; i++) 
    {
        *ptrArr[i] = (*ptrArr[i]) * (*ptrArr[i]);
    }
    printf("\nSquared values:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: %d\n", i + 1, arr[i]);
    }

    return 0;
}
int main()
{
    int n1 =10, n2 =20, n3 = 30;
    int *
}