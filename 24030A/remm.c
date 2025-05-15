#include <stdio.h>

void removeChar(char str[], char ch) {
    int i, j = 0;
    char result[100];  // temporary string

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ch) {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';

    // Copy back to original string
    for (i = 0; result[i] != '\0'; i++) {
        str[i] = result[i];
    }
    str[i] = '\0';
}

int main() {
    char str[100], ch;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the character to remove: ");
    scanf("%c", &ch);

    removeChar(str, ch);

    printf("String after removing '%c': %s", ch, str);

    return 0;
}
