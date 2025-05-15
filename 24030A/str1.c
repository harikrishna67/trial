#include<stdio.h>
#include<string.h>
int main()
{
    char source[100];
    char needle[100];
    scanf("%[^\n]%*c", source);
    scanf("%[^\n]", needle);

    char *res = strstr(source, needle);

    res ? printf("String found\nstring is ---> %s\n", res) : printf("String not found");
    return 0;

}
