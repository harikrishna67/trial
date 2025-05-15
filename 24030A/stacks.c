#include<stdio.h>

 int print(int n)
 {
    if(n<1)
    {
        return 0;
    }
    else
    {
        printf("%d\n",n);
        print(n-1);
    }
 }
 int main()
 {
    int num;
    printf("Enter limit:");
    scanf("%d", &num);

    print(num);

 }