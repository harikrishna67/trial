#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[], char *env[])
{
for (int i=0;env[i]!=NULL; i++)
// {
//     printf("%s\n", env[i]);
// }
char *result = getenv("HOME");
printf("%s\n", result);
return 0;
}