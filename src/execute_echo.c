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

void execute_echo(int number)
{
	if(command[number].argcount==1)
	{
		printf("\n");
	}
	else
	{
		environment=getenv(command[number].argval[1]);
		if(environment!=NULL)
		{
			printf("%s\n",environment);
			return;
		}


		int len1 = strlen(command[number].argval[command[number].argcount-1]);
		int flag_start=0;
		if(command[number].argval[1][0] == '\'' && command[number].argval[command[number].argcount-1][len1-1] == '\'')
		{
			for(int i=0;i<strlen(echo_arr)-1;i++)
			{			
				if(flag_start==1)
				{
					if(echo_arr[i]=='\'')
						break;
					printf("%c",echo_arr[i]);
				}
				if(echo_arr[i]=='\'')
				{
					flag_start=1;
				}
			}
			printf("\n");
		}
		else if(command[number].argval[1][0] == '\"')
		{
			//printf("in");
			//printf("\"");
			for(int i=0;i<strlen(echo_arr)-1;i++)
			{	
				//printf("%d",flag_start);		
				if(flag_start==1)
				{
					if(echo_arr[i]=='\"')
						break;
					printf("%c",echo_arr[i]);
					//printf("%c\n",echo_arr[i]);
					
				}
				if(echo_arr[i]=='\"')
				{
					flag_start=1;
				}
			}
			printf("\n");
		}
		else if(command[number].argval[1][0] != '\"' && command[number].argval[command[number].argcount-1][len1-1] == '\"')
		{
			printf("Error: Wrong Input\n");
		}
		else if(command[number].argval[1][0] == '\"' && command[number].argval[command[number].argcount-1][len1-1] != '\"')
		{
			printf("Error: Wrong Input\n");
		}
		else if(command[number].argval[1][0] != '\'' && command[number].argval[command[number].argcount-1][len1-1] == '\'')
		{
			printf("Error: Wrong Input\n");
		}
		else if(command[number].argval[1][0] == '\'' && command[number].argval[command[number].argcount-1][len1-1] != '\'')
		{
			printf("Error: Wrong Input\n");
		}
		else
		{
			for(int i=1;i<command[number].argcount;i++)
			{
				printf("%s ",command[number].argval[i]);
			}
			printf("\n");
		}
	}
	
}
