#include <stdio.h>
int main()
{
char arr = {0,1,2,3,4,5,6,7,8,9}
char ch;
scanf("%c", &ch);
int res;
for(int i=0;i<8;i+=)
{
    res=(1<<i)>>i;

}
if (res==1)
{
    arr[i] | res;
}
else if (res ==0)
{
    arr[i] & res;
}
return 0;



    int mask = (1 << n) - 1; 

    int num_cleared = num & mask;  
    int val_bits = val & mask; 
    int result = num_cleared | val_bits;

    return result;


}
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d", &num);

}