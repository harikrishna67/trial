#include<stdio.h>

int main()
{
    int choice;
    printf("Enter your dish:\n");
    printf("1. Biriyani\n");
    printf("2. payasam\n");
    printf("3. burger\n");
    printf("4. pizza\n");
    printf("5. dosa\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("you entered Biriyani\n");
        break;
        case 2:
        printf("you entered payasam\n");
        break;
        case 3:
        printf("you entered Burger\n");
        break;
        case 4:
        printf("you entered pizza\n");
        break;
        case 5:
        printf("you entered dosa\n");
        break;
        default:
        printf("you dont have nothing\n");

    }
}
