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
#include <fcntl.h>
#include <signal.h>

void execute_bg(int number)
{
	if(command[number].argcount<2)
		fprintf(stderr,"Job number not specified\n");
	else
	{
		int jobno = atoi(command[number].argval[1]);

		if( jobno < job_counter)
        {
            kill(job[jobno].pid,SIGCONT);
            if(strcmp(job[jobno].status_of_job,"Stopped")==0)
			{
				printf("Job number %d has started in background\n",jobno);
			}
			else
			{
				printf("Job number %d is already running\n",jobno);
			}
        }
        else
            printf("Job number does not exist\n");

	}
}