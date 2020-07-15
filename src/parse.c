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

void parse( char *line , char **tokens , char* delim)
{
    char *temp;

    //Splitting line by delim and saving it into temp
    temp = strtok( line , delim );
    int i = 0;
    while( temp != NULL )
    {
		//
		//printf("%s",temp);
        tokens[i++] = temp;
        temp = strtok( NULL , delim );
    }
	if(i>1)
	{
		if(strcmp(delim,"|")==0)
			is_pipe=1;
	}
}