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

void execute_fg(int number)
{
    if(command[number].argcount<2)
        fprintf(stderr,"Job number not specified\n");
    else
    {
        int jobno = atoi(command[number].argval[1]);
        if( jobno < job_counter)
        {
            kill(job[jobno].pid,SIGCONT);
            job_counter--;
            delete_job(job[jobno].pid);
            wait(NULL);
        }
        else
            printf("Job number does not exist\n");
    }

}