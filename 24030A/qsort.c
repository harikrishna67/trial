#include<stdio.h>
#include<stdlib.h>
int ascend(const void *p1,const void *p2)
{
    return *(int *)p1 > *(int *)p2;
}
int decend(const void *p1,const void *p2)
{
    return *(int *)p1 < *(int *)p2;
}
int main()
{
    int arr[10] = {1,-3,0,5,3, 4,7,9,8,7};
    qsort(arr, 10, sizeof(int), ascend);
    for(int i=0;i<10;i++)
    {
        printf("%d ", arr[i]);
    }
    qsort(arr, 10, sizeof(int), decend);
    for(int i=0;i<10;i++)
    {
        printf("\n%d ", arr[i]);
    }
}