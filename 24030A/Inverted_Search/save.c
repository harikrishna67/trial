#include "invert.h"
int save_database(char str2[],hash_t arr[])
{
	FILE *fname = fopen(str2,"w");
	if(fname == NULL)
		return FAILURE;
	for(int i = 0;i < 27;i++)
        {
		if(arr[i].hlink != NULL)
                {
			Main *temp = arr[i].hlink;
                        while(temp != NULL)
                        {
				fprintf(fname,"#%d;%s;%d;",i,temp->word,temp->fcount);
                                Sub *temp2 = temp->slink;
                                while(temp2 != NULL)
                                {
					fprintf(fname,"%s;%d;",temp2->file,temp2->wcount);
                                        temp2 = temp2->nslink;
                                }
				fprintf(fname,"#\n");
                                temp = temp->mlink;
                        }
                }
        }
	return SUCCESS;
}
