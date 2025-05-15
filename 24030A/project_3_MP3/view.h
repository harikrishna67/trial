#include<stdio.h>

typedef struct
{
    char *filename;
    
}view;

status read_and_validate_view(int argc, char *argv[], view *viewinfo);
