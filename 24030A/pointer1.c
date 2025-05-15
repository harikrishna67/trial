#include<stdio.h>
int main()
{
    int num = 50;
    int *iptr = 100;
    printf("Num is %d\n", num);
    printf("iptr is %p\n", iptr);
    printf("*iptr is %d\n", *iptr);
}