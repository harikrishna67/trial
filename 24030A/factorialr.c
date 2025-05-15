#include <stdio.h>

int main() 
{

    int num;

    printf("Enter a number:");
    scanf("%d", &num);
    int res = factorial(num);
    printf("Factorial is %d\n", res);

    return 0;

}


int factorial(int n) 
{

    if (n < 1)  

        return 1;

    else

        return n * factorial(n - 1);

}



`