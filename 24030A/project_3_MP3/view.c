#include<stdio.h>
#include"view.h"
#include"type.h"

status read_and_validate_view(int argc, char *argv[], view *viewinfo)
{
    if (argc == 3)
    {
        if ( strcmp( ( strstr( argv[2], "." ) ), ".mp3" ) == 0 )
        {
            viewinfo->filename = argv[2];                  
        }
        else
            return e_failure;
    }
}

status 