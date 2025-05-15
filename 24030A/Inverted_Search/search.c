#include "invert.h"
#include <ctype.h>

int search_database(char str[20],hash_t arr[])
{
	int index;
	if(islower(*str))
	{
		index = *str - 'a';
	}
	else if(isupper(*str))
	{
		index = *str - 'A';
	}
	else
	{
		index = 26;
	}
	Main *temp = arr[index].hlink;
	Sub *temp2;

	while(temp != NULL)
	{
		if(strcmp(str,temp->word) == 0)
		{
			printf("WORD (%s) IS FOUND IN (%d) FILE",temp->word,temp->fcount);
			temp2 = temp->slink;
			while(temp2 != NULL)
			{
				printf(", IN (%s) (%d) TIME",temp2->file,temp2->wcount);
				temp2 = temp2->nslink;
			}
			printf("\n");
			return SUCCESS;
		}
		temp = temp->mlink;
	}
	printf("word is not present\n");
	return FAILURE;
}
