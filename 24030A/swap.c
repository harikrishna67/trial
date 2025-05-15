#include <stdio.h>

void sort012(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Count number of 0s, 1s, and 2s
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    // Refill the array with sorted values
    int i = 0;

    while (count0--) arr[i++] = 0;
    while (count1--) arr[i++] = 1;
    while (count2--) arr[i++] = 2;
}

int main() {
    int arr[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (only 0s, 1s, and 2s):\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort012(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
