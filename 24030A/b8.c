#include<stdio.h>
int main()
{
    FILE *fptr = fopen ("text.txt", "w+");
    char str[100];
    while(1)
    {
        printf("\nEnter the name:");
        scanf(" %[^\n]", str);
        fprintf(fptr, "%s\n", str);
    }
        fclose(fptr);
}