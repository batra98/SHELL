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

void execute_remindme(int number)
{
	if(strcmp(command[number].argval[1],"")==0)
	{
		fprintf(stderr, "Error : specify time\n");
		return;
	}

	for(int j=0;j<strlen(command[number].argval[1]);j++)
	{
		//printf("%c\n",command[number].argval[4][j]);
		if((command[number].argval[1][j]) <= 57 && (command[number].argval[1][j]) >= 48)
		{

		}
		else
		{
			fprintf(stderr, "Invalid syntax\n");
			return;
		}
	}
	
	time_remind = atoi(command[number].argval[1]);

	//printf("%d\n",time_remind);

	if(strcmp(command[number].argval[2],"")==0)
	{
		strcpy(message,"Default message");
	}
	else
	{
		strcpy(message,command[number].argval[2]);
	}
	//printf("%s\n",message);

	reminder_pid = fork();

	if (reminder_pid < 0) {
        perror("ERROR");
    }
    else if(!reminder_pid) {
        sleep(time_remind);
        exit(0);
    }
    else
    { 
       	    	printf("Reminder with Pid: %lld has been set.\n",(long long int)reminder_pid);	    
	}
}
