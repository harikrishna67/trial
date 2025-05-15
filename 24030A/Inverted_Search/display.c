#include "invert.h"
int display_database(hash_t arr[])
{
	printf("-------------------------------------------------------\n");
	printf("Index  word         filecount  filename       wordcount\n");
	printf("-------------------------------------------------------\n");
	for(int i = 0;i < 27;i++)
	{
		if(arr[i].hlink != NULL)
		{
			Main *temp = arr[i].hlink;
			while(temp != NULL)
			{
				printf("%-6d %-12s %-11d",i,temp->word,temp->fcount);
				Sub *temp2 = temp->slink;
				int count = 0;
				while(temp2 != NULL)
				{
					if(count > 0)
					{
						printf("%31s","");
					}
					printf("%-14s %-10d\n",temp2->file,temp2->wcount);
					temp2 = temp2->nslink;
					count++;
				}
				temp = temp->mlink;
			}
		}
	}
	return SUCCESS;
}
