#include "headers.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/wait.h>

void getinput_2()
{
	if(input!=NULL)
		free(input);
	if(curr!=NULL)
		free(temp);
	
	int i=0,j=0;

	ssize_t buf = 0;
	getline(&input,&buf,stdin);
	//printf("%s\n",input);

	input_1 = (char *)malloc(strlen(input) * sizeof(char));
    strncpy(input_1,input,strlen(input));

    echo_arr=strtok(input_1,"\n");

	

	curr = strtok(input,";\n");

	while(curr!=NULL)
	{
		//printf("%s\n",curr);
		strcpy(full_command[i],curr);
		i++;
		curr = strtok(NULL,";\n");

	}	
	comm_size=i;

	/*for(int k=0;k<i;k++)
	{
		free(command[k].argval);
	}*/







	/*command[0].argval[0] = curr;

	while(curr!=NULL)
	{
		printf("%s\n",curr);
		if(curr==NULL)
		{
			command[i].argval[j++]=curr;
		}
		else if(strcmp(curr,";")==0)
		{
			command[i].argval[j++] = NULL;
            command[i].argcount = j;
            j = 0;i++;
		}
		else
        {
            command[i].argval[j++] = curr;
        }
		curr=strtok(NULL," \t\n");
	}
	//command[i].argval[j++] = NULL; // handle last command separately
    command[i].argcount = j;
    i++;
	for(int k=0;k<i;k++)
	{
		//printf("%s\n",command[k]);
		printf("%d\n",command[k].argcount);
	}*/
}