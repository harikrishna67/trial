#include<stdio.h>
float mean(int arr[],int size)
{
    if (size<0)
    return 0;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof (arr[0]);
    printf("%f", mean(arr,size));
}