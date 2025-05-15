

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// int main() {
//     const char *original = "Hello, world!";
//     char *duplicate = strdup(original); 

//     if (duplicate != NULL) {
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);

//         free(duplicate);  
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *s) 
{
    
    size_t len = strlen(s) + 1;  
    char *dup = (char *)malloc(100);
    
    
    if (dup == NULL) {
        return NULL;  
    }

    
    strcpy(dup, s);
    

    return dup;
}

int main() 
{
    const char *original = "Hello, world!";
    

    char *duplicate = my_strdup(original);
    
    
    if (duplicate != NULL) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        

        free(duplicate);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

