#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *cp = fopen(argv[1], "r");
    if(cp==NULL)
    {
        printf("File is not there\n");
        return 0;
    }
	FILE *dp = fopen(argv[2], "w");

	fseek(cp, 0, SEEK_END);
	
	long int size = ftell(cp);
	char buffer[size];
	rewind(cp);
	
	fread(buffer, 1, size, cp);
	fwrite(buffer, 1, size, dp);
	
	fclose(cp);
	fclose(dp);
}