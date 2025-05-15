
#include<stdio.h>
int main()
{
    char str[100];
    printf("Enter your name:");
    scanf("%[^\n]",str);
    printf("String is %s\n", str);

}