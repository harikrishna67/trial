#include<stdio.h>

unsigned long long int factorial(int n)
{
    if(n<1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);

    }
}
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    printf("Factorial id %llu",factorial(num));
}