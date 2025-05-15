#include <stdio.h>
#include <stdint.h>  
int circular_right_shift(int num, int n) 
{
    
    int bits = 32;
    
    
    n = n % bits;

   
    return (num >> n) | (num << (bits - n));
}


void print_binary(int num) 
{
    unsigned int mask = 1 << 31; 

    for (int i = 0; i < 32; i++) {

        putchar((num & mask) ? '1' : '0');
        putchar(' '); 
        num <<= 1; 
    }
    putchar('\n');
}

int main() 
{
    int num, n;

  
    printf("Enter num: ");
    scanf("%d", &num);

    printf("Enter n: ");
    scanf("%d", &n);

   
    int result = circular_right_shift(num, n);


    printf("Result in Binary: ");
    print_binary(result);

    return 0;
}
