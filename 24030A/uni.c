#include<stdio.h>
int main()
{
    int size;
    printf("Enter the size");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array elements:");
    for(int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]== arr[j])
            {
                for(int k=j;k<size;k++)
                arr[k] = arr[k+1];
                j--;
                size--;
            }
        }
    }
    printf("unique elements are:");
    for(int i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
}