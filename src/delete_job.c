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

void delete_job(int jobpid)
{
    int i;
    int flag=0;
    for(i=1;i<job_counter;i++)
    {
        if( job[i].pid == jobpid )
            flag=1;

        if(flag==1)
            job[i]=job[i+1];
    }
}