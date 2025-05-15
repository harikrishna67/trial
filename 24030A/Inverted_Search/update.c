#include "invert.h"
int update_database(hash_t arr[])
{
	for (int i=0; i < 27; i++)
	{
		arr[i].index = i;
                arr[i].hlink = NULL;
	}
	
	char newfile[100];
	int index;

	printf("Enter the file to update :\n");
        scanf("%s", newfile);
        FILE *fptr = fopen(newfile, "r");
	
	if (fptr == NULL)
        {
		printf("ERROR: FILE NOT FOUND\n");
                return FAILURE;
	}
	
	while (fscanf(fptr, "%s", newfile) != EOF)
        {
		if (newfile[0] != '#')
                {
			return FAILURE;
                }

		index = atoi(strtok(&newfile[1], ";"));
		Main *m_new = malloc(sizeof(Main));

		if (m_new == NULL)
		{
			return FAILURE;
		}
		
		m_new->mlink = NULL;
		strcpy(m_new->word, strtok(NULL, ";"));
		m_new->fcount = atoi(strtok(NULL, ";"));
		Sub *s_new = malloc(sizeof(Sub));
		Sub *stemp;

		if (s_new == NULL)
		{
	    		return FAILURE;
		}
		s_new->nslink = NULL;
		strcpy(s_new->file, strtok(NULL, ";"));
		s_new->wcount = atoi(strtok(NULL, ";"));
		m_new->slink = s_new;
		stemp = s_new;

		for (int i = 0; i < (m_new->fcount) - 1; i++)
		{
	    		Sub *s_new = malloc(sizeof(Sub));
	    		if (s_new == NULL)
	    		{
				return FAILURE;
	    		}

	    		s_new->nslink = NULL;
	    		strcpy(s_new->file, (strtok(NULL, ";")));
	    		s_new->wcount = atoi(strtok(NULL, ";"));
			stemp->nslink = s_new;
	    		stemp = s_new;
		}
		Main *temp = arr[index].hlink;
		if (temp == NULL)
		{
	    		arr[index].hlink = m_new;
		}
		else
		{
	    		while (temp->mlink)
	    		{
				temp = temp->mlink;
	    		}
	    		temp->mlink = m_new;
		}
    	}
    	fclose(fptr);
    	return SUCCESS;
}

