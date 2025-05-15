#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to compare two strings case-insensitively
int stringsEqualIgnoreCase(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] && str2[i]) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return 0; // Not equal
        }
        i++;
    }

    // If both strings ended at the same time, they are equal
    return str1[i] == '\0' && str2[i] == '\0';
}

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';  // Remove newline

    if (stringsEqualIgnoreCase(str1, str2)) {
        printf("The strings are equal (ignoring case).\n");
    } else {
        printf("The strings are NOT equal.\n");
    }

    return 0;
}
