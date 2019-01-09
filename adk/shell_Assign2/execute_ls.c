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
#include "headers.h"

void execute_ls(int flag,int number)
{
	int j=0;
	int count=0;

	if(flag==1)
	{
		if(command[number].argcount==1)
			count=scandir(".",&list,0,alphasort);
		else if(strcmp(command[number].argval[1],"~")==0)
		{
			count=scandir(home,&list,0,alphasort);
		}
		else
		{
			//printf("in\n");
			count=scandir(command[number].argval[1],&list,0,alphasort);

			if(count==-1)
			{
				//	printf("in\n");
				perror("Error: ");
				return;
			}
		}
	}
	else if(flag==2)
	{
		if(command[number].argcount==2)
			count=scandir(".",&list,0,alphasort);
		else if(strcmp(command[number].argval[2],"~")==0)
		{
			count=scandir(home,&list,0,alphasort);
		}
		else
		{
			//printf("in\n");
			count=scandir(command[number].argval[2],&list,0,alphasort);
			if(count==-1)
			{
				//	printf("in\n");
				perror("Error: ");
				return;
			}
		}
	}
	char temp[1000];

	if(count > 0)
	{
		for(int i=0;i<count;i++)
		{
			//printf("%s\n",list[i]->d_name);]
			strcpy(temp,list[i]->d_name);
			//printf("%c\n",temp[0]);
			if(flag==1)
			{
				if(temp[0]=='.')
				{
					continue;
				}
				else
				{
					printf("%30s",list[i]->d_name);
					j++;
				}
				if(j%5==0)printf("\n");
			}
			else if (flag==2)
			{
				printf("%30s",list[i]->d_name);
				if(i%5==0 && i!=0)printf("\n");
			}
		}
	}
	printf("\n");

	for(int i=0;i<count;i++)
	{
		free(list[i]);
	}
	free(list);

}