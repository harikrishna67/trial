#include<stdio.h>
int main()
{
    char ch;
    printf("enter a number");
    scanf("%c", &ch);
    switch (ch)
    {
        case 'A':
        printf("you entered A\n");
        break;
        case 'B':
        printf("you entered B\n");
        break;
        default:
        printf("try again");
    }
    return 0;
}