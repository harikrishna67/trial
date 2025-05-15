#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of strings: ");
    scanf("%d", &n);

    // Allocate an array of pointers for n strings
    char *str[n];

    // Read each string dynamically using realloc
    getchar();  // Consume the newline character left by scanf
    for (int i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);

        // Initial allocation for each string
        int capacity = 10;  // Start with space for 10 characters
        int len = 0;        // Current length of the string
        str[i] = malloc(capacity * sizeof(char));  // Allocate initial memory

        if (str[i] == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        // Read characters one by one
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            // If the current string buffer is full, reallocate more space
            if (len == capacity - 1) {  // -1 for null-terminator space
                capacity *= 2;  // Double the buffer size
                str[i] = realloc(str[i], capacity * sizeof(char));

                if (str[i] == NULL) {
                    printf("Memory reallocation failed\n");
                    return 1;
                }
            }
            str[i][len++] = ch;  // Store the character
        }

        str[i][len] = '\0';  // Null-terminate the string
    }

    // Print the strings
    printf("\nYou entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(str[i]);
    }

    return 0;
}
