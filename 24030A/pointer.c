#include<stdio.h>
int main()
{
    int num = 20;
    int *iptr = &num;
    printf("Num is %d\n", num);
    printf("iptr is %p\n", iptr);
    printf("*iptr is %d\n", *iptr);
    printf(" Add of iptr is %p\n", &iptr);
}