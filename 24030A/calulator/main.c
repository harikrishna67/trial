#include<stdio.h>
float add(int n1,int n2);
float sub(int n1,int n2);
float mul(int n1,int n2);
float div(int n1,int n2);



int main() {
    int n1, n2;
    char choice;
    printf("Enter the two values: ");
    scanf("%d%d", &n1, &n2);
    printf("\nEnter your choice:\n");
    printf("+.addition\n");
    printf("-.subraction\n");
    printf("*.multipication\n");
    printf("/.division\n");
    scanf(" %c", &choice);
    

    
    switch(choice) {
        case '+':
           add(n1,n2);
            break;
        case '-':
             sub(n1,n2);
            break;
        case '*':
             mul(n1,n2);
            break;
        case '/':
        if(n1!=0)
         {
            div(n1,n2);
          }
          else
          {
            printf("division not allowed");
          }
        break;
        
    }
    
    return 0;
}