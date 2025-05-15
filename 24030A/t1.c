#include<stdio.h>
void sum(int *a,int *b)
{
    *a =  *a +*b;
}
int main()
{
   
    int a = 2,b = 5;
    sum(&a,&b);
    printf("%d", a);
    

}