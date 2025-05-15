// #include<stdio.h>
// #define SQUARE(a) a*a

// int main()
// {
//     int x=4;
//     printf("%d\n", SQUARE(x));
//     return 0;
// }
// #include<stdio.h>
// #define PI 3.14
// int main()
// {
//     int rad =3;
//     float area = PI * rad * rad;
//     printf("Area is %g\n", area);
//     return 0;
// }
#include<stdio.h>
#define contact(x, y) x##y
int main()
{
    int int_num = 10;
    printf("%d\n",contact(int,_num));
    return 0;

}