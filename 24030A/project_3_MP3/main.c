#include<stdio.h>
#include"view.h"
#include<string.h>
#include"type.h"

operation_type check_operation_type(char * argv[])
{
    if ( (strcmp(argv[1], "-v") ) == 0 ) 
            return e_view;
    else if ( (strcmp(argv[1], "-e") ) == 0 ) 
            return e_edit;
    else if ((strcmp(argv[1], "--help"))==0)
            return e_help;
    else
            return e_unsupported;
}

int main(int argc, char *argv[])
{
    if(check_operation_type(argv) == e_view)
    {
        view viewinfo;
        if(read_and_validate_view(argc, argv, &viewinfo) == e_success)
        {
            printf("View option selected\n");
            if(view_function(&viewinfo) == e_success )
            {
                printf("view function is success\n");
            }
            else
            {
                printf("Error\n");
                return 0;
            }
        }
        else
        {
            printf("Error\n");
            return 0;
        }
    }
}

