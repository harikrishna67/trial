#include<stdio.h>
#include<string.h>
int main()
{
   char str[3][10] = {"Array", "of", "string"};
   for (int i=0;i<3;i++)
   {
    printf(" %s\n", str[i]);

   }
   strcpy(str[0], "Hello");
    for (int i=0;i<3;i++)
   {
    printf(" %s\n", str[i]);

   }                                                        
}