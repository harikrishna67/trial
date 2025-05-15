#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char str[80];
    int i =0;
    printf("Enter the string:");
    scanf("%s", str);
    if(isalpha(str[0]!=0))
    {
        printf("INvalid");
    }
    while(str[i] != '\0')
    {

        if (isdigit(str[i])) 
        {
    
            int count = str[i] - '0';
            char ch = str[i + 1];          
            for (int j = 0; j < count; j++) 
            {
                printf("%c", ch);          
            }
        }
        
        i++; 
    }

}


