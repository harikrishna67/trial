#include<stdio.h>
void foo2();
void foo()
{
    printf("Hi foo\n");
    foo2();
    printf("Thank YOU foo2\n");
}
