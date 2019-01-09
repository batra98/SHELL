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

void execute_clock(int number)
{
	int time_number,time_interval;
	char clk[100];

	if(strcmp(command[number].argval[1],"-t") != 0 || strcmp(command[number].argval[3],"-n") != 0 || command[number].argcount != 5)
	{
		//printf("%s %s %d\n",command[number].argval[1],command[number].argval[3],command[number].argcount);
		fprintf(stderr, "Invalid syntax\n");
	}

	//printf("%s\n",command[number].argval[4]);

	for(int i=0;i<strlen(command[number].argval[2]);i++)
	{
		//printf("%c\n",command[number].argval[2][i]);
		if((command[number].argval[2][i]) <= 57 && (command[number].argval[2][i]) >= 48)
		{

		}
		else
		{
			fprintf(stderr, "Invalid syntax\n");
			return;
		}
	}

	for(int j=0;j<strlen(command[number].argval[4]);j++)
	{
		//printf("%c\n",command[number].argval[4][j]);
		if((command[number].argval[4][j]) <= 57 && (command[number].argval[4][j]) >= 48)
		{

		}
		else
		{
			fprintf(stderr, "Invalid syntax\n");
			return;
		}
	}


	time_interval=atoi(command[number].argval[2]);
	time_number=atoi(command[number].argval[4]);

	strcpy(clk,"/sys/class/rtc/rtc0");

	char date[100],time[100];
	char date_show[50],time_show[50];
	FILE *date_pointer;
	FILE *time_pointer;

	strcpy(date,clk);
	strcat(date,"/date");

	strcpy(time,clk);
	strcat(time,"/time");

	

	for(int k=1;k<=time_number;k++)
	{

		date_pointer = fopen(date,"r");
		time_pointer = fopen(time,"r");

		if(date_pointer == NULL)
		{
			fprintf(stderr, "Error in opening /sys/class/rtc/rtc0/date\n");
			return;
		}

		if(time_pointer == NULL)
		{
			fprintf(stderr, "Error in opening /sys/class/rtc/rtc0/time\n");
			return;
		}

		fscanf(date_pointer,"%s",date_show);
		printf("%s, ",date_show);

		fscanf(time_pointer,"%s",time_show);
		printf("%s\n",time_show);

		fclose(date_pointer);
		fclose(time_pointer);





		sleep(time_interval);

		
	}

	



}