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



void generate_commandline()
{
	//chdir("~");
	int flag=0,i,j,k;
	getcwd(current,1000);
	char full_address[1000]="~";
	//printf("%s %s\n",current,home);


	if(strlen(home)<=strlen(current))
	{
		for(i=0;i<strlen(home);i++)
		{
			if(home[i]!=current[i])
			{
				flag=1;
				break;
			}
		}
	}
	else
	{
		flag=1;
	}
	//printf("%d\n",flag);

	if(flag==0)
	{
		for( j=i , k=1 ; current[j]!='\0' ; j++,k++ )
		{
			full_address[k]=current[j];
			//k++;
		}
		printf("<%s@%s:%s>",user_name,host,full_address);
	}
	else
	{
		//printf("%s\n","in" );
		printf("<%s@%s:%s>",user_name,host,current);
	}
	/*printf("%s\n",current);
	printf("%s\n",full_address );*/
	
}