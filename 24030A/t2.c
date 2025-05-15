#include<stdio.h>
int main()
{
    int x=0,y=0,z=1;
    int a = x?++y:!x?z++:y++;
    printf("a is %d ", a);
    printf("x is %d ", x);
    printf("y is %d ", y);
    printf("z is %d ", z);
}