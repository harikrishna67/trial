#include<stdio.h>
void sum_pro(int n1, int n2, int *s, int *p)
{
    *s = n1 + n2;
    *p = n1 * n2;
}
int main()
{
    int num1 = 3,num2 = 5;
    int sum, pro;
    sum_pro(num1, num2, &sum, &pro);
    printf("sum is %d\n", sum);
    printf("Product is %d\n", pro);
}