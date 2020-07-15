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

void execute_cd(int number)
{
	char home_1[1000];

    strcpy(home_1,home);

    int i;
    int len = strlen(home);

    //If command is 'cd' , change to ~
    //Changing ~ to home directory of executable
    //Then using chdir to change directory
    //printf("dfsfs%sdfsdfdfds\n",args[1]);
    //printf("%d\n",argcount);
    if( command[number].argcount == 1 )
    {
    	//printf("in 1\n");
        chdir(home);
    }
    else
    {
    	if ( command[number].argval[1][0] == '~' )
    	{
	    	//printf("in 2\n");
	        for( i=1 ; command[number].argval[1][i]!='\0' ; i++ )
	        {
	            home_1[i+len-1] =command[number].argval[1][i];
	        }
	        home_1[i+len-1]='\0';
	        if( chdir(home_1) != 0 )
	            perror("Error");
	    }
	    else if ( chdir(command[number].argval[1]) != 0)
	    {
	    	//printf("in 3\n");
	        perror("Error");
	    }
    }
    
}