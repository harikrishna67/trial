//to declare the strings inside all memmory segment
//we can resize this by using  realloc

// #include<stdlib.h>
// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     int n;
//     printf("Enter number of strings:");
//     scanf("%d", &n);
//     char *str[n];
//     for(int i=0;i<n;i++)
//     {
//         str[i] = malloc(25);

//     }
//     for(int i=0;i<n;i++)
//     {
//         scanf( " %[^\n]", str[i]);
//     }
//     for(int i=0;i<n;i++)
//     {
//         printf(" %s\n", str[i]);
//     }
//     strcpy(str[3], "Messi");
//     for (int i=0;i<n;i++)
//    {
//     printf(" %s\n", str[i]);

//    }
//    realloc();
//     for(int i=0;i<n;i++)
//     {
//         free(str[i]);
//     }
// }
//array of strings inside heap segment

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,i;
    printf("Enetr no of strings : ");
    scanf("%d",&n);

    char *str[n];
    for(i=0;i<n;i++)
    {
        str[i]=malloc(25);

    }
    for(i=0;i<n;i++)
    {
        scanf(" %[^\n]",str[i]);
    }
    printf("The strings are : \n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",str[i]);
    }

    strcpy(str[3],"Jadeja");
    strcpy(str[4],"Sanju");

    printf("The modified strings are : \n");
    for(i=0;i<n;i++)
    {
        printf("%s\n",str[i]);
    }
    for(i=0;i<n;i++)
    {
        str[i]=realloc(str[i],strlen(str[i])+1);

    }

    for(i=0;i<n;i++)
    {
        free(str[i]);
    }


}