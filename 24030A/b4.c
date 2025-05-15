//find the number which comes in power of 2 or not using bitwise.


#include<stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    int count = 0;
    for(int i = 31;i>=0;i--)
    {
        int res = num & (1<<i);
        if (res)
        count++;
    if (count ==2)
    break;
    }
    if (count == 1)
    {
        printf("yes");
    }
    else
    {
        printf(" no");

    }
}
