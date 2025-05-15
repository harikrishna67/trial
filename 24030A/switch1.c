#include<stdio.h>
int main()
{
    int num;
    scanf("%d", &num);

    switch (num > 15)
    {
    case 0:
    printf("num is 10\n");
    break;
    case 1:
    printf("num is 20\n");
    break;
    default:
    printf("try again\n");
    }
    return 0;
}