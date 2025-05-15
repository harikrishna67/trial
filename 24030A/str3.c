#include<stdio.h>

void mystrcat( char *dest,char *source,int len)
{
    char *ptr = dest +len;
    while(*source != '\0')
    {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    //return dest;
}

int mystrlen(char *d)
{
    int l=0;
    while(d[l]!='\0')
    {
        l++;
    }
    return l;
}

int main()
{
    char sor[100];
    char des[100];
    scanf("%[^\n]",sor);
    getchar();
    scanf("%[^\n]",des);
    int len = mystrlen(des);
    mystrcat(des,sor,len);
    printf("String is : %s\n",des);
    return 0;
    
}