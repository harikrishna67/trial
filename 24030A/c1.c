// C program to find the second largest element in the array
// using one traversal

#include <stdio.h>

// function to find the second largest element in the array
int getSecondLargest(int arr[], int n) {
    int largest = -1, secondLargest = -1;

    // finding the second largest element
    for (int i = 0; i < n; i++) {

        // If arr[i] > largest, update second largest with
        // largest and largest with arr[i]
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
      
        // If arr[i] < largest and arr[i] > second largest, 
        // update second largest with arr[i]
        else if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main() 
{
    int size;
  printf("enter the size:");
         scanf("%d",&size);
         int arr[size];
         printf("Enter the elements");
         for(int i=0;i<size;i++)
         {
           scanf("%d", &arr[i]);
         }
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", getSecondLargest(arr, n));

    return 0;
}