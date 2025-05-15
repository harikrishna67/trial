#include<stdio.h>
int main()
{
    int num1,num2,num3;
    scanf("%d%d", &num1,&num2);
    num3 = num1>num2?num1:num2;
    printf("Largest number is %d", num3);
}