#include<stdio.h>
#define SIZEOF(x) ((char *) (&x+1)-(char *) (&x))
int main()
{
    int a;
    char b;
    double c;
    printf("size of int: %zu bytes\n", SIZEOF(a));
    printf("size of char %zu bytes\n", SIZEOF(b));
    printf("size of double %zu bytes\n", SIZEOF(c));
    return 0;
}