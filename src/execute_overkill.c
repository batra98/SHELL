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

void execute_overkill(int number)
{
	int i;
	if(job_counter==1)
	{
		fprintf(stderr,"No Background Processes\n");
	}
	else
	{
		for(i=1;i<job_counter;i++)
		{
			//printf("%d\n",job[i].pid);			
			kill(job[i].pid,9);
		}
	}
	
	
}
