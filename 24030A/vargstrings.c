#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void print(int count, ...) 
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) 
    {
        printf("%s ",(va_arg(args, char*))); //for strlen %ld is taken and strlen(v_arg)
    
    }

    va_end(args);
}

int main() 
{
    
    print(3, "Hari", "is", "best");
    return 0;
}
