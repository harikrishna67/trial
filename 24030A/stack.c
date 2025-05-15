#include<stdio.h>
int modify(int num)
{
    num = num + 5;
    return num;
}
int main()
{
    int num = 10;
   int res = 0;
    modify(num);
    
    printf("Modified value of num is: %d", res);

    int n = 100;
    int res2 = modify(n);
    printf("%d\n", res2);
}
