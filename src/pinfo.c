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

void pinfo(int number)
{
	char proc[100];
	char status[100];


	strcpy(proc,"/proc/");
	//printf("%s\n",command[number].argval[1]);

	if(strcmp(command[number].argval[1],"")==0)
	{
		strcat(proc,"self");		
	}
	else
	{
		strcat(proc,command[number].argval[1]);
	}

	strcpy(status,proc);
	strcat(status,"/stat");
	//printf("%s\n",status);

	FILE *stat=fopen(status,"r");
	if(stat == NULL)
	{
		fprintf(stderr, "Error in opening /proc/%s/stat\n", command[number].argval[1]);
		return;
	}
	
	int p_pid;
	char p_status;
	char p_name[100];

	fscanf(stat,"%d %s %c",&p_pid,p_name,&p_status);
	printf("PID -- %d\n",p_pid);
	printf("PROCESS STATUS -- %c\n",p_status);

	fclose(stat);

	strcpy(status,proc);
	strcat(status,"/statm");

	FILE *mem = fopen(status,"r");
	if(mem == NULL)
	{
		fprintf(stderr, "Error in opening /proc/%s/statm\n", command[number].argval[1]);
		return;
	}

	int vir_mem;
	fscanf(mem,"%d",&vir_mem);
	printf("VIRTUAL MEMORY ALLOCATED -- %d\n",vir_mem);
	fclose(mem);

	strcpy(status,proc);
	strcat(status,"/exe");
	char exe_path[1000]="",rel_path[1000]="~";
	int flag=0,i,j,k;

	//readlink(status, exe_path, sizeof(exe_path));
	if(readlink(status, exe_path, sizeof(exe_path)) < 0)
	{
		fprintf(stderr, "Error in reading /proc/%s/exe\n", command[number].argval[1]);
		return;
	}

	
	//fscanf(p_path,"%s",exe_path);
	//printf("%s %s\n",exe_path,home);

	if(strlen(home)<=strlen(exe_path))
	{
		for(i=0;i<strlen(home);i++)
		{
			if(home[i]!=exe_path[i])
			{
				flag=1;
				break;
			}
		}
	}
	else
	{
		flag=1;
	}
	//printf("%d\n",flag);

	if(flag==0)
	{
		for( j=i , k=1 ; exe_path[j]!='\0' ; j++,k++ )
		{
			rel_path[k]=exe_path[j];
			//k++;
		}
		//printf("<%s@%s:%s>",user_name,unameData.sysname,full_address);
		printf("EXECUTABLE PATH -- %s\n",rel_path);
	}
	else
	{
		//printf("%s\n","in" );
		printf("EXECUTABLE PATH -- %s\n",exe_path);
	}


}