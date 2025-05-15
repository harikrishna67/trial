#include<stdio.h>
int main()
{
    int size,i,j;
    printf("enter the size:");
    scanf("%d", &size);
    int arr[size];
    for(i=0;i<size;i++)
    {
      scanf("%d", &arr[i]);  
    }
    int count =1;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if (arr[i]==arr[j])
            count++;
            
        }

    }
        printf("%d : %d times", arr[i],count);
    
}