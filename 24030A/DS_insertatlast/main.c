#include "main.h"
int main()
{
    Slist * head = NULL;
    int data,choice;
    char ch;
    do
    {
        printf("1.Insert at last\n2. Print list\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            printf("Enter the data to be inserted at last: ");
            scanf("%d", &data);

            if(insert_at_last(&head, data) == FAILURE)
            {
                printf("INFO : Insert at last failure\n");
            }
            else
            {
                printf("INFO : Insert at last successful\n");
            }
            break;
        
        case 2:
            print_list(head);
            break;

        default:
            printf("INFO : Invalid option\n");
        }

    printf("\nDo you want to continue(Y/y)?");
    scanf("\n%c",&ch);
    }while (ch == 'Y' || ch == 'y');
    
    
}