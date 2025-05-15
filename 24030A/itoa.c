#include <stdio.h>
int main()
{
char buffer[10];
int value = 123;

sprintf(buffer, "%d", value);  // Convert integer to string

// buffer now contains "123"
printf("hello");
//printf("%s",buffer);
return 0;
}
