#include<stdio.h>
void commonele(int arr[], int len1,int arr2[], int len2)
{
    printf("\nCommon elements: ");
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
        {
            if(arr[i]== arr2[j])
            {
                printf("%d ", arr[i]);
                break;
            }
        }
    }
}
int main()
{
    int size,i;
    printf("enter the size:");
    scanf("%d", &size);
    int arr[size];
    printf("enter the elemenets:");
    for(i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);

    }
    int size2,j;
    printf("enter the size:");
    scanf("%d", &size2);
    int arr2[size2];
    printf("enter the elemenets:");
    for(j=0;j<size2;j++)
    {
        scanf("%d", &arr2[j]);
    }
    commonele(arr,size,arr2,size2);
    return 0;

}