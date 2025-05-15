#include<stdio.h>
int length(char *cptr) 
{
    int len = 0;
    while (cptr[len] !='\0')
    {
        len++;
        
    }
    return len;
}
int main()
{
    char str[100];
    printf("Enter String: ");
    //scanf("%s",str);//&already in bulit//can read only upto space not after space
    scanf("%[^\n]",str);
    printf("String: %s\n",str);
    printf("Size: %d\n",length(str));
}