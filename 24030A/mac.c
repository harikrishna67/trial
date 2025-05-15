#include <stdio.h>

#define SECONDS_IN_YEAR 31536000  // 365 * 24 * 60 * 60

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    printf("Seconds in the year %d: %d\n", year, SECONDS_IN_YEAR);
    return 0;
}
