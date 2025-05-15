#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }
    int arr[n], result[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove even elements
    j = 0; // index for the new array
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 != 0) {
            result[j] = arr[i]; // keep only odd numbers
            j++;
        }
    }

    // Print the result
     printf("Array after removing even numbers:\n");
     for(i = 0; i < j; i++)

        {
            printf("%d ", result[i]);
        }
        printf("\n");
    

    return 0;
}
