// void *ptr;
// int num = 10;
// ptr = &num; 
// printf("%d", *((int*)ptr));


#include <stdio.h>

void printData(void *ptr, char type) 
{
    if (type == 'i') 
    {
        printf("Integer: %d\n", *((int*)ptr));
    } 
    else if (type == 'f') 
    {

        printf("Float: %.2f\n", *((float*)ptr));
    } 
    else if (type == 'c') 
    {
        printf("Char: %c\n", *((char*)ptr));
    }
}

int main() 
{
    int i = 10;
    float f = 3.14;
    char c = 'A';

    void *ptr;

    ptr = &i;
    printData(ptr, 'i');  // Pass void pointer for int

    ptr = &f;
    printData(ptr, 'f');  // Pass void pointer for float

    ptr = &c;
    printData(ptr, 'c');  // Pass void pointer for char

    return 0;
}

