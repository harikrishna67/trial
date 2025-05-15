#include<stdio.h>

// void swap(void *a, void *b, size_t size) 
// {
  
//     unsigned char temp[size];

  
//     for (size_t i = 0; i < size; i++) 
//     {
//         temp[i] = ((unsigned char*)a)[i];
//     }

    
//     for (size_t i = 0; i < size; i++) {
//         ((unsigned char*)a)[i] = ((unsigned char*)b)[i];
//     }

 
//     for (size_t i = 0; i < size; i++) {
//         ((unsigned char*)b)[i] = temp[i];
//     }
// }

// int main() {
//     int x = 5, y = 10;
//     float a = 3.14, b = 2.71;
//     char c = 'X', d = 'Y';

//     // Swap integers
//     printf("Before swap (int): x = %d, y = %d\n", x, y);
//     swap(&x, &y, sizeof(int));
//     printf("After swap (int): x = %d, y = %d\n", x, y);

//     // Swap floats
//     printf("\nBefore swap (float): a = %.2f, b = %.2f\n", a, b);
//     swap(&a, &b, sizeof(float));
//     printf("After swap (float): a = %.2f, b = %.2f\n", a, b);

//     // Swap characters
//     printf("\nBefore swap (char): c = %c, d = %c\n", c, d);
//     swap(&c, &d, sizeof(char));
//     printf("After swap (char): c = %c, d = %c\n", c, d);

//     return 0;
// }
int main()
{
    int num1 = 10;
    int num2 = 20;

    printf("After Swapping: \n");
    +
    swap (&num1, &num2, sizeof(num1));
}
void swap(void *p1, void *p2. int n)
{
    int i;
    for(int i=0;i<n;i++)
    {
        char temp = *((char  *)p1 + 1);
        *((char *)p1 + i) = *((char *)p2 + i);
        *((char  *)p1 + 1) = temp;
    }
}