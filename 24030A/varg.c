#include <stdio.h>
#include <stdarg.h>

int addition(int count, ...) 
{
    va_list args;
    va_start(args, count);
    int sum=0;
    for (int i = 0; i < count; i++) 
    {
        sum = sum + va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int main() 
{
    int res = addition(3,1,2,3,4); 
    printf("%d ", res);
    return 0;
}
