#include<stdio.h>

int main()
{
    char choice;
    printf("Enter a direction\n");
    scanf("%c", &choice);
    switch(choice)
    {
        case 'N':
        case 'n':
        printf("you entered north direction\n");
        break;
        case 'W':
        case 'w':
        printf("you entered west direction\n");
        break;
        case 'S':
        case 's':
        printf("you entered south direction\n");
        break;
        case 'E':
        case 'e':
        printf("you entered east direction\n");
        break;
        default:
        printf("try again\n");
    }
    return 0;
}