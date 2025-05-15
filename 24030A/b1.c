#include<stdio.h>
int main()
{
    int num = 150,n = 5, pos = 9;
    int mask = ((1<<n)-1)<<(pos - n + 1);
    num  =num|mask;
    printf("%d\n", num);
    return 0;
}