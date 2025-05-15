#include<stdio.h>
#include<stdlib.h>
int main(int argc, char **argv[])
{
    float avg;
    int sum =0;
    for(int i=0;i<argv[i]!= NULL;i++)
    {
        sum = sum + atoi(argv[i]);
    }
    avg = (float)sum/(argc -1);
    printf("Sum is %d\n", sum);
    printf("avg is %g\n", avg);
    return 0;
}