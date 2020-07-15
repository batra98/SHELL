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

/*void function_exit()
{
    exit_flag = 1;
    return;
}*/


void executable(int number,int fd[])
{
	//int fd[2];
	//printf("%s",tempting[number+1]);
	int flag;
	int redir_in=0,redir_out=0,pipeer=0,p=1;
	if(pipe(fd) != 0)
	{
		perror("Pipe Failed");
	}
	pid_t pid;
    int state;
	int j;
    char *cmd=command[number].argval[0];
    char *args[command[number].argcount];
    //printf("%d\n",isBackground);
	//printf("%s\n",cmd);
    if(isBackground==0)
    {
    	//printf("%d\n",command[number].argcount);

    	for(j=0;j<command[number].argcount;j++)
    	{
    		args[j]=command[number].argval[j];
    		//printf("%s\n",args[j]);
    		
    	}
		args[j]='\0';
    }
    else if(isBackground==1)
    {
    	//printf("%d\n",command[number].argcount);
    	for(j=0;j<command[number].argcount-1;j++)
    	{
    		args[j]=command[number].argval[j];
    		//printf("%s\n",command[number].argval[j]);
    	}
		args[j]='\0';
    }
	
    pid = fork();
	stop_pid=pid;

    if (pid < 0) {
        perror("ERROR");
    }
    else if(pid==0) 
	{
		
		
		
		if(INFILE != 0)
		{
			dup2(INFILE,STDIN_FILENO);
			close(INFILE);
			//printf("%d",dup2(INFILE,STDIN_FILENO));
			//redir_in=1;
			
		}
		if(OUTFILE != 1)
		{
			dup2(OUTFILE,STDOUT_FILENO);
			close(OUTFILE);
			//redir_out=1;
			//printf("%d",dup2(OUTFILE,STDOUT_FILENO));
		}

		if(tempting[number+1]!=NULL) 
        {
            dup2(fd[1],STDOUT_FILENO);
			//close(fd[1]);
			//pipeer=1;
            //printf("%d",dup2(fd[1],STDIN_FILENO));
        }
		/*printf("hello in child");
		printf("hello in child");
		printf("%d %d\n",INFILE,OUTFILE);*/

		/*if(strcmp(command[j].argval[0],"cd")==0 && isBackground == 0)
		{
			execute_cd(j);
		}
		else if(strcmp(command[j].argval[0],"pwd")==0 && isBackground == 0)
		{
			printf("in pwd\n");
			//execute_pwd();
			exit(0);
		}
		else if(strcmp(command[j].argval[0],"echo")==0 && isBackground == 0)
		{					
			execute_echo(j);					
		}
		else if(strcmp(command[j].argval[0],"ls")==0 && isBackground==0)
			{
				if(command[j].argcount==1)
				{
					execute_ls(1,j);
				}
				else
				{
					if(strcmp(command[j].argval[1],"-a")==0)
					{
						if(strcmp(command[j].argval[2],"-l")!=0)
							execute_ls(2,j);
						else
							execute_lsl(2,j);
					}
					else if(strcmp(command[j].argval[1],"-l")==0)
					{
						if(strcmp(command[j].argval[2],"-a")!=0)
						{
							//printf("in\n");
							execute_lsl(1,j);
						}
						else
							execute_lsl(2,j);
					}
					else if(strcmp(command[j].argval[1],"-la")==0 || strcmp(command[j].argval[1],"-al")==0)
					{
						execute_lsl(2,j);
					}
					else
					{
						execute_ls(1,j);
					}
				}

			}
			else if(strcmp(command[j].argval[0],"pinfo")==0 && isBackground == 0)
			{
				pinfo(j);
			}
			else if(strcmp(command[j].argval[0],"remindme")==0 && isBackground==0)
			{
				execute_remindme(j);
			}
			else if(strcmp(command[j].argval[0],"clock")==0 && isBackground==0)
			{
				execute_clock(j);
			}
			else if(strcmp(command[j].argval[0],"exit")==0 && isBackground==0)
			{
				function_exit();
			}
			else if(strcmp(command[number].argval[0],"jobs")==0 && isBackground == 0)
			{
				execute_jobs(number);
			}*/
			//else
			//{
				if ( execvp(cmd, args) == -1)
				{
					fprintf(stderr, "Command not found\n");
					exit(0);
				}
			//}			


	
        

		/*if(redir_in==1)
		{
			close(INFILE);
		}
		if(redir_out==1)
		{
			close(OUTFILE);
		}
		if(pipeer==1)
		{
			close(fd[1]);
		}*/
		//exit(0);
    }
    else
    {
		/*printf("hello in parent");
		printf("%d %d\n",INFILE,OUTFILE);*/
	    if(isBackground==0)
		 {
			
	        /*wpid = waitpid (pid, &state, WUNTRACED);
			//printf("%d",wpid);
	        for (int i = 0;; i++) {
	        if (!WIFEXITED(state) && !WIFSIGNALED(state)) {
	            wpid = waitpid (pid, &state, WUNTRACED);
	            continue;
	            }
	        break;
	        }*/
			waitpid(pid,&flag,WUNTRACED);
	    }
		else if(isBackground==1)
	    {
			//printf("in 2");
			job[job_counter++].pid = pid;
			//printf("%d %d\n",job[job_counter-1].pid,job_counter);	    	
	    	printf("Process with Pid: %lld has started.\n",(long long int)pid);

	    }
		

		INFILE=fd[0];
		close(fd[1]);

		/*printf("hello in parent");
		printf("%d %d\n",INFILE,OUTFILE);*/
        
	

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