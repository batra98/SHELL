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


void execute_lsl(int flag,int number)
{
	long long int size=0;
	//printf("%s\n",command[number].argval[1]);
	int count=scandir(".",&list,0,alphasort);
	struct stat f_stat;
	char temp[1000],timer[1000];


	if(count >= 0)
	{
		for(int i=0;i<count;i++)
		{
			strcpy(temp,list[i]->d_name);
			if(flag==1)
			{
				if(temp[0]=='.')
				{
					//printf("in 1\n");
					continue;
				}
				else if(stat(list[i]->d_name,&f_stat)==0)
				{
					//printf("in 2\n");
					size+=f_stat.st_blocks;
					//printf("%lld ",size);
					//printf("%d",S_ISDIR(f_stat.st_mode)==0);

					if(S_ISDIR(f_stat.st_mode)!=0)
					{
						printf("%1s","d");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IRUSR)!=0)
					{
						printf("%1s","r");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IWUSR)!=0)
					{
						printf("%1s","w");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IXUSR)!=0)
					{
						printf("%1s","x");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IRGRP)!=0)
					{
						printf("%1s","r");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IWGRP)!=0)
					{
						printf("%1s","w");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IXGRP)!=0)
					{
						printf("%1s","x");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IROTH)!=0)
					{
						printf("%1s","r");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IWOTH)!=0)
					{
						printf("%1s","w");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IXOTH)!=0)
					{
						printf("%1s","x");
					}
					else
					{
						printf("%1s","-");
					}

					printf("%2ld ",(unsigned long)(f_stat.st_nlink));
                	printf("%s ",(getpwuid(f_stat.st_uid))->pw_name);
                	printf("%s ",(getgrgid(f_stat.st_gid))->gr_name);
                	printf("%10lld ",(unsigned long long)f_stat.st_size);
                	strftime (timer,14,"%h %d %H:%M",localtime(&f_stat.st_mtime));
                	printf("%s ",timer);
                	printf("%s\n",list[i]->d_name);




				}

			}

			if(flag==2)
			{
				
				if(stat(list[i]->d_name,&f_stat)==0)
				{
					//printf("in 2\n");
					size+=f_stat.st_blocks;
					//printf("%lld ",size);
					//printf("%d",S_ISDIR(f_stat.st_mode)==0);

					if(S_ISDIR(f_stat.st_mode)!=0)
					{
						printf("%1s","d");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IRUSR)!=0)
					{
						printf("%1s","r");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IWUSR)!=0)
					{
						printf("%1s","w");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IXUSR)!=0)
					{
						printf("%1s","x");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IRGRP)!=0)
					{
						printf("%1s","r");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IWGRP)!=0)
					{
						printf("%1s","w");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IXGRP)!=0)
					{
						printf("%1s","x");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IROTH)!=0)
					{
						printf("%1s","r");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IWOTH)!=0)
					{
						printf("%1s","w");
					}
					else
					{
						printf("%1s","-");
					}

					if((f_stat.st_mode & S_IXOTH)!=0)
					{
						printf("%1s","x");
					}
					else
					{
						printf("%1s","-");
					}

					printf("%2ld ",(unsigned long)(f_stat.st_nlink));
                	printf("%s ",(getpwuid(f_stat.st_uid))->pw_name);
                	printf("%s ",(getgrgid(f_stat.st_gid))->gr_name);
                	printf("%10lld ",(unsigned long long)f_stat.st_size);
                	strftime (timer,14,"%h %d %H:%M",localtime(&f_stat.st_mtime));
                	printf("%s ",timer);
                	printf("%s\n",list[i]->d_name);




				}

			}

			//printf("\n");
		}
		printf("Total %lld\n",size/2);
	}
	for(int i=0;i<count;i++)
	{
		free(list[i]);
	}
	free(list);
	//printf("\n");
}
