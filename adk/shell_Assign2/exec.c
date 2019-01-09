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

void executable(int number)
{
	pid_t pid, wpid;
    int state;
    char *cmd=command[number].argval[0];
    char *args[command[number].argcount];
    //printf("%d\n",isBackground);
    if(isBackground==0)
    {
    	//printf("%d\n",command[number].argcount);

    	for(int j=0;j<command[number].argcount;j++)
    	{
    		args[j]=command[number].argval[j];
    		//printf("%s\n",args[j]);
    		
    	}
    }
    else if(isBackground==1)
    {
    	//printf("%d\n",command[number].argcount);
    	for(int j=0;j<command[number].argcount-1;j++)
    	{
    		args[j]=command[number].argval[j];
    		//printf("%s\n",command[number].argval[j]);
    	}
    }
    pid = fork();

    if (pid < 0) {
        perror("ERROR");
    }
    else if(!pid) {
        if ( execvp(cmd, args) == -1)
            fprintf(stderr, "Command not found\n");
        exit(EXIT_FAILURE);
    }
    else
    {
	    if(isBackground==0) {
	        wpid = waitpid (pid, &state, WUNTRACED);
	        for (int i = 0;; i++) {
	        if (!WIFEXITED(state) && !WIFSIGNALED(state)) {
	            wpid = waitpid (pid, &state, WUNTRACED);
	            continue;
	            }
	        break;
	        }
	    }
	    else if(isBackground==1)
	    {
	    	
	    	printf("Process with Pid: %lld has started.\n",(long long int)pid);

	    }
	

		cmd=NULL;
		for(int j=0;j<command[number].argcount;j++)
		{
			args[j]=NULL;
		}
		free(cmd);
		if(isBackground==0)
	    {

	    	for(int j=0;j<command[number].argcount;j++)
	    	{
	    		free(args[j]);
	    		
	    	}
	    }
	    else if(isBackground==1)
	    {
	    	for(int j=0;j<command[number].argcount-1;j++)
	    	{
	    		free(args[j]);
	    		
	    	}
	    }
	    //free(args);
		isBackground=0;
	}
}