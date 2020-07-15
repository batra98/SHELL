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

int checkOutfile(char *tokens)
{
	int single=0;

	for(int h=0;tokens[h]!='\0';h++)
	{
		//printf("%c\n",tokens[h]);
		if(tokens[h]=='>')
		{
			if(tokens[h+1]=='>')
			{
				single=1;
				break;
			}
		}
	}

    int i=0;
    char *temp[100]={NULL} ;

    parse( tokens , temp , ">" );

    if(temp[1]!=NULL)
    {
		//printf("%s\n",temp[0]);
        char *temp1[100]={NULL};
        parse( temp[1] , temp1 , " \t\n" );


		if(single==0)
		{
			OUTFILE = open(temp1[0],O_TRUNC | O_WRONLY | O_CREAT, 0644);
			if(OUTFILE<0)
			{
				fprintf(stderr,"Unable to open file\n");
			}	
		}
		else if(single==1)
		{
			OUTFILE = open(temp1[0],O_APPEND|O_WRONLY|O_CREAT,0644);
			if(OUTFILE<0)
			{
				fprintf(stderr,"Unable to open file\n");
				return -1;
			}
		}	
        //OUTFILE = open(temp1[0],O_TRUNC | O_WRONLY | O_CREAT, 0644);
    }
    else
        OUTFILE=1;

	return 0;	
}

