#include<stdio.h>
int my_strcpy(char[],char[]);

int main()
{
    char source[100];
    char destination[100];
    printf("Enter your string: ");

    scanf("%[^\n]", source);

    my_strcpy(destination, source);
    printf("Given string is:%s\n",destination);
    return 0;

}
int my_strcpy(char d[],char s[])
{
    while(*s != '\0')
    {
        *d++ = *s++;
    }
    *d = '\0';
}