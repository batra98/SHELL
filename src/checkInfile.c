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


int checkInfile(char *tokens)
{
    int i=0;
    char *temp[100]={NULL} ;

    parse( tokens , temp , "<" );

    if(temp[1]!=NULL)
    {
        char *temp1[100]={NULL};
        parse( temp[1] , temp1 , " \t\n" );

        INFILE = open(temp1[0],O_RDONLY);
		if(INFILE<0)
		{
			fprintf(stderr,"File does not exist\n");
			return -1;
		}
    }

	return 0;
}
