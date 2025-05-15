#include "invert.h"

int read_validate(int argc, char *argv[], Slist **head)
{
    *head = NULL;
    int i, flag = 0;

    for (i = 1; i < argc; i++)
    {
        char *ptr = strrchr(argv[i], '.');
        if (ptr && strcmp(ptr, ".txt") == 0)
        {
            FILE *fptr = fopen(argv[i], "r");
            if (fptr != NULL)
            {
                fseek(fptr, 0, SEEK_END);
                if (ftell(fptr) > 0)
                {
                    fseek(fptr, 0, SEEK_SET);

                    if (*head == NULL)
                    {
                        if (insert_at_last(head, argv[i]) == FAILURE)
                        {
                            printf("ERROR\n");
                        }
                        else
                        {
                            printf("(%s) SUCCESSFULLY ADDED\n", argv[i]);
                        }
                    }
                    else
                    {
                        Slist *temp = *head;
                        while (temp != NULL)
                        {
                            if (strcmp(temp->data, argv[i]) == 0)
                            {
                                flag = 1;
                                break;
                            }
                            temp = temp->link;
                        }
                        if (flag == 0)
                        {
                            if (insert_at_last(head, argv[i]) == FAILURE)
                            {
                                printf("ERROR\n");
                            }
                            else
                            {
                                printf("(%s) SUCCESSFULLY ADDED\n", argv[i]);
                            }
                        }
                        else
                        {
                            printf("ERROR: DUPLICATE FILE NAME FOUND (%s)\n", argv[i]);
                        }
                    }
                }
                else
                {
                    printf("ERROR: DATA NOT FOUND IN FILE (%s)\n", argv[i]);
                }
                fclose(fptr); 
            }
            else
            {
                printf("ERROR: UNABLE TO OPEN FILE (%s)\n", argv[i]);
            }
        }
        else
        {
            printf("ERROR: FILE SHOULD HAVE .txt EXTENSION (%s)\n", argv[i]);
        }
    }
    return SUCCESS;
}
