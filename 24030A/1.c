#include<stdio.h>
int main()
{


fun (int n);
{
    int i = 0;
    if(i<n)
    {
        printf("%d", i++);
        fun(n-1);
    }
    printf("%d", i);
}
}