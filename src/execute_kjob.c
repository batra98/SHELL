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

void execute_kjob(int number)
{
	if(command[number].argcount<3)
	{
		fprintf(stderr,"Less number of arguments\n");		
	}
	else
	{
		if(atoi(command[number].argval[1])> job_counter)
		{
			fprintf(stderr,"Job number does not exist.\n");
		}
		else
		{
			kill(job[atoi(command[number].argval[1])].pid,atoi(command[number].argval[2]));
			if(atoi(command[number].argval[2])==9)
			{
				delete_job(job[atoi(command[number].argval[1])].pid);
				job_counter--;
			}
		}
	}
}
