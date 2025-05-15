
#include<stdio.h>
int main()
{
    char arr[8]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07};
    char ch2 = 0,ch = 'A';
    // scanf("%c",&ch);
    for(int i=0; i<8; i++)
    {
        char res = ch & (1<<i);//ger
        res = res >> i;
        arr[i]= arr[i] & (~1);//clear
        arr[i]= arr[i] | res;//set
    }
    for(int i=0; i<8; i++)
    {
        int res = arr[i] & 1;
        ch2 = ch2 | (res << i);
    }
    for(int i=0; i<8; i++)
    {
        printf("%x\n",arr[i]);
    }
    printf("%c\n",ch);

}