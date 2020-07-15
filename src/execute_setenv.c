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

void execute_setenv(int number)
{	
	if(setenv(command[number].argval[1],command[number].argval[2],1)!=0)
	{
		perror("ERROR");
	}
	//printf("%s\n",getenv(command[number].argval[1]));
}