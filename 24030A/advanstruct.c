
#include<stdio.h>
struct M
{
    char str1[19];
    int n;
    char str2[20];

}M1;
int main()
{
    printf("size is --> %u\n", sizeof(M));
    printf("%hhd\n", &M1.str1);
    printf("%hhd\n", &M1.n);
    printf("%hhd\n", &M1.str2);
}