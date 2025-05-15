#include<stdio.h>
#include<string.h>
int main()
{
    int num = 20;
    
    int *iptr;
    iptr = &num;

    printf("Num is %d\n", num);
    printf("Address of num is %p\n", iptr);

    int *ptr;
    char *cptr;
    float *fptr;
    double *dptr;
    printf("size of ptr is %1u\n", sizeof(ptr));
    printf("size of cptr is %1u\n", sizeof(cptr));
    printf("size of fptr is %1u\n", sizeof(fptr));
    printf("size of dptr is %1u\n", sizeof(dptr));
return 0;
}

