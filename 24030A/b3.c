#include<stdio.h>
int main()
{
    int num = 150,n = 5, pos = 9;
    int mask = (((1<<n)-1)<<(pos - n + 1));
    int res = num & mask;
    res = res >> (pos - n + 1);
    
    printf("%d\n", res);
    return 0;
}