#include<stdio.h>
int main()
{
    char ch;
    printf("enter a char:");
    scanf("%c", &ch);
    switch(ch)
    {
        case '0'...'9':
        printf("you entered a digit\n");
        break;
        case 'A'...'Z':
        case 'a'...'z':
        printf("you entered a alphabet\n");
        break;
        default:
        printf("you entered a symbol\n");
    }
    return 0;
}