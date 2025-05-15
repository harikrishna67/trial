#include "invert.h"
#include <ctype.h>

int create_database(hash_t arr[], Slist **head)
{
	char buf[50];
	int size =27;
	for(int i = 0;i < size;i++)
	{
		arr[i].index = i;
		arr[i].hlink = NULL;
	}

	Slist *temp = *head;
	char cur[20];
	while(temp != NULL)
	{
		FILE *fptr = fopen(temp->data,"r");
		while(fscanf(fptr,"%s",buf) != EOF)
		{
			int index;

			if(islower(buf[0]))
			{
				index = buf[0] % 97;
			}
			else if(isupper(buf[0]) != 0)
			{
				index = buf[0] % 65;
			}
			else
			{
				index = 26;
			}

			Main *mnew = malloc(sizeof(Main));
			if(mnew == NULL)
				return FAILURE;
			Sub *snew = malloc(sizeof(Sub));
			if(snew == NULL)
				return FAILURE;

			mnew->fcount = 1;
			strcpy(mnew->word,buf);
			mnew->mlink = NULL;

			snew->wcount = 1;
			strcpy(snew->file,temp->data);
			snew->nslink = NULL;

			if(arr[index].hlink == NULL)
			{
				mnew->slink = snew;
				arr[index].hlink = mnew;
			}
			else if(arr[index].hlink != NULL)
			{
				Main *temp2 = arr[index].hlink;
				Sub *prev,*temp4;
				Main *temp3;

				int flag = 0,flag2 = 0;
				while(temp2 != NULL)
				{
					temp3 = temp2;
					if(strcmp(temp2->word,mnew->word) == 0)
					{
						prev = temp2->slink;
						while(prev != NULL)
						{
							temp4 = prev;
							if(strcmp(prev->file,snew->file) == 0)
					                {
								prev->wcount++;
								flag = 1;
								break;
					                }
							prev = prev->nslink;
				                }
						if(flag == 0)
						{
							temp4->nslink = snew;
							temp2->fcount++;
						}
						flag2 = 1;
						break;
					}
					temp2 = temp2->mlink;
				}
				if(flag2 == 0)
                                {
					temp3->mlink = mnew;
					mnew->slink = snew;
                                }
			}
		}
		temp = temp->link;
	}

	return SUCCESS;
}
