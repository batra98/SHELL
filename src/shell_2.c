#include "headers.h"
/*void parse( char *line , char **tokens , char* delim)
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
}*/

void function_exit()
{
    exit_flag = 1;
    return;
}

void execute_jobs(int number)
{
	if(job_counter==1)
	{
		printf("No background processes running\n");
	}
	char proc[100];
	char status[100];


	
	//printf("%s\n",command[number].argval[1]);

	
	
	int p_pid;
	char p_status;
	char p_name[100];
	char job_pid[100];

	

	



	int i;
	//printf("%d",job_counter);
	
	for(i=1;i<job_counter;i++)
	{
		
		sprintf(job_pid,"%lld",(long long int)job[i].pid);
		//printf("%s",job_pid);
		strcpy(proc,"/proc/");		
		strcat(proc,job_pid);
		strcpy(status,proc);
		strcat(status,"/stat");
		//printf("%s\n",status);

		FILE *stat=fopen(status,"r");
		if(stat == NULL)
		{
			//memset(job[i].status_of_job,0,strlen(job[i].status_of_job));
			//strcpy(job[i].status_of_job,"Stopped");
			//fprintf(stderr, "Error in opening /proc/%lld/stat\n", (long long int)job[i].pid);
			//return;
		}
		else
		{
			//printf("in running");
			//memset(job[i].status_of_job,0,strlen(job[i].status_of_job));
			

			fscanf(stat,"%d %s %c",&p_pid,p_name,&p_status);
			if(p_status=='T')
			{
				strcpy(job[i].status_of_job,"Stopped");
			}
			else if(p_status=='S')
			{
				strcpy(job[i].status_of_job,"Sleeping");
			}
			/*printf("PID -- %d\n",p_pid);
			printf("PROCESS STATUS -- %c\n",p_status);*/
			fclose(stat);
		}
		

		
		
		

		printf("[%d] %s %s [%d]\n",i,job[i].status_of_job,job[i].name,job[i].pid);

		
		
	}

	

}


void parse_cmd_space(char *line,int number)
{
	int k,j=0;
	

	
		//printf("%s\n",command[k].full);
		curr=strtok(line," \t\n");
		while(curr!=NULL)
		{
			//printf("%s\n",curr);
			strcpy(command[number].argval[j++],curr);
			//printf("%s\n",command[k].argval[j-1]);
			curr=strtok(NULL," \t\n");
		}
		command[number].argcount=j;
		//printf("%d",command[number].argcount);
		j=0;
		

	


}

/*for(int k=0;k<i;k++)
	{
		//printf("%s\n",command[k].full);
		curr=strtok(command[k].full," \t\n");
		while(curr!=NULL)
		{
			//printf("%s\n",curr);
			strcpy(command[k].argval[j++],curr);
			//printf("%s\n",command[k].argval[j-1]);
			curr=strtok(NULL," \t\n");
		}
		command[k].argcount=j;
		j=0;

	}*/
/*int checkInfile(char *tokens)
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
}*/

/*int checkOutfile(char *tokens)
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
}*/

/*void execute_setenv(int number)
{	
	if(setenv(command[number].argval[1],command[number].argval[2],1)!=0)
	{
		perror("ERROR");
	}
	//printf("%s\n",getenv(command[number].argval[1]));
}*/

/*void execute_unsetenv(int number)
{
	if(unsetenv(command[number].argval[1])!= 0)
	{
		perror("ERROR");
	}

}*/

void sig_handler(int sig)
{
	//printf("signal = %d\n",sig);
	if(sig == SIGINT || sig == SIGQUIT)
	{
		printf("\n");
        generate_commandline();
        fflush(stdout);
	}
	if(sig == SIGTSTP)
	{
		//printf("%d\n",stop_pid);
		
		
		
		if(stop_pid!=0)
		{
			//printf("%s",current_command);
			job[job_counter].pid=stop_pid;
			strcpy(job[job_counter].name,current_command);
			job_counter++;
			kill(stop_pid,SIGSTOP);

			/*for(int i=0;i<job_counter;i++)
			{
				printf("%s\n",job[i].name);
			}*/
		}
	}
	
	

	

}

/*void delete_job(int jobpid)
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
}*/

/*void execute_fg(int number)
{
    if(command[number].argcount<2)
        fprintf(stderr,"Job number not specified\n");
    else
    {
        int jobno = atoi(command[number].argval[1]);
        if( jobno < job_counter)
        {
            kill(job[jobno].pid,SIGCONT);
            job_counter--;
            delete_job(job[jobno].pid);
            wait(NULL);
        }
        else
            printf("Job number does not exist\n");
    }

}*/

/*void execute_bg(int number)
{
	if(command[number].argcount<2)
		fprintf(stderr,"Job number not specified\n");
	else
	{
		int jobno = atoi(command[number].argval[1]);

		if( jobno < job_counter)
        {
            kill(job[jobno].pid,SIGCONT);
            if(strcmp(job[jobno].status_of_job,"Stopped")==0)
			{
				printf("Job number %d has started in background\n",jobno);
			}
			else
			{
				printf("Job number %d is already running\n",jobno);
			}
        }
        else
            printf("Job number does not exist\n");

	}
}
*/

/*void execute_kjob(int number)
{
	if(command[number].argcount<3)
	{
		fprintf(stderr,"Less number of arguments\n");		
	}
	else
	{
		if(atoi(command[number].argval[1])> job_counter)
		{
			fprintf(stderr,"Job number does not exist.\n");
		}
		else
		{
			kill(job[atoi(command[number].argval[1])].pid,atoi(command[number].argval[2]));
			if(atoi(command[number].argval[2])==9)
			{
				delete_job(job[atoi(command[number].argval[1])].pid);
				job_counter--;
			}
		}
	}
}
*/
/*void execute_overkill(int number)
{
	int i;
	if(job_counter==1)
	{
		fprintf(stderr,"No Background Processes\n");
	}
	else
	{
		for(i=1;i<job_counter;i++)
		{
			//printf("%d\n",job[i].pid);			
			kill(job[i].pid,9);
		}
	}
	
	
}*/

int main(int argc, char *argv[])
{
	INFILE=0;
	OUTFILE=1;
	check_1=0;
	check_2=0;

	argcount=0;
	input=NULL;
	input_1=NULL;
	input_2=NULL;
	temp=NULL;
	echo_arr=NULL;
	exit_flag=0;
	curr=NULL;
	comm_size=0;
	isBackground=0;
	ppid=0;
	environment=NULL;


	int j=0;

	for(int o=0;o<100;o++)
	{
		tempting[o]=NULL;
	}

	

	int check_uname;
	user_name=getenv("USER");
	//write(1,user_name,strlen(user_name));


	check_uname=uname(&unameData);

	if(check_uname<0)
	{
		perror("System_Name not found");
	}
	

	getcwd(home,1000);
	gethostname(host,1000);
	//printf("%s\n",home);

	clear_screen();
	job_counter=1;
	
	while(exit_flag==0)
	{
		check_1=0;
		check_2=0;
		environment=NULL;

		signal(SIGINT,sig_handler);
		signal(SIGQUIT,sig_handler);
		signal(SIGTSTP,sig_handler);

		
		
		
		generate_commandline();

		getinput_2();
		//printf("%s\n",args[0]);
		//printf("%d\n",strcmp(args[0],"cd"));

		for(int i=0;i<comm_size;i++)
		{
			INFILE=0;
			OUTFILE=1;
			
			for(int o=0;o<100;o++)
			{
				tempting[o]=NULL;
			}
			/*fd[0]=0;
			fd[1]=1;*/
			int fd[2];
			is_pipe=0;
			//printf("full=%s",command[i].full);
			parse( full_command[i] , tempting , "|" );
			j=0;
			
			while(tempting[j]!=NULL)
			{
				/*printf("12");
				printf("%s\n",tempting[j]);*/

				//char *tokens[100] = {NULL};
            	/*char *temp1[100]={NULL};
            	char *temp2[100]={NULL};*/

				check_1 = checkOutfile(tempting[j]);
            	check_2 = checkInfile(tempting[j]);
				//printf("%d %d\n",check_1,check_2);
				//printf("%d %d\n",INFILE,OUTFILE);
				//printf("infile=%d  outfile=%d\n",INFILE,OUTFILE);
				//printf("%s  %d\n",tempting[j],j);

				/*parse( tempting[j] , temp1 , "<" );
				parse( temp1[0] , temp2 , ">" );*/
				parse_cmd_space(tempting[j],j);
				// l=0;
				//printf("%s",temp1[1]);
				/*while(temp2[l]!=NULL)
				{
					printf("%s",temp2[l]);
					l++;
				}
				printf("\n");*/		
				/*for(int g=0;g<command[j].argcount;g++)
				{
					printf("%s\n",command[j].argval[g]);
				}*/
				//printf("%s\n",tempting[j]);
				strcpy(current_command,command[j].argval[0]);


				for(int g=0;g<command[j].argcount;g++)
				{
					if(strcmp(command[j].argval[g],"&")==0)
					{
						isBackground=1;
					}
				}
				//signal(SIGCHLD,sig_handler);
				if(isBackground==1)
				{
					//printf("in 1");'
					/*printf("%s",full_command[i]);
					strcpy(job[job_counter].name,command[j].full);*/
					strcpy(job[job_counter].name,command[j].argval[0]);
					for(int g=1;g<command[j].argcount-1;g++)
					{
						strcat(job[job_counter].name," ");
						strcat(job[job_counter].name,command[j].argval[g]);
					}
				}
				if(is_pipe == 0)
				{
					if(strcmp(command[j].argval[0],"cd")==0 && isBackground == 0)
					{
						execute_cd(j);
					}
					else if(strcmp(command[j].argval[0],"pwd")==0 && isBackground == 0)
					{
						int stout_temp;
						stout_temp=dup(1);
						//printf("in jobs\n");
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

						execute_pwd();

						dup2(stout_temp,STDOUT_FILENO);
						close(stout_temp);
					}
					else if(strcmp(command[j].argval[0],"echo")==0 && isBackground == 0)
					{

						int stout_temp;
						stout_temp=dup(1);
						//printf("in jobs\n");
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
						

						execute_echo(j);	

						dup2(stout_temp,STDOUT_FILENO);
						close(stout_temp);				
					}
					else if(strcmp(command[j].argval[0],"ls")==0 && isBackground==0)
					{
						int stout_temp;
						stout_temp=dup(1);
						//printf("in jobs\n");
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

						dup2(stout_temp,STDOUT_FILENO);
						close(stout_temp);

					}
					else if(strcmp(command[j].argval[0],"pinfo")==0 && isBackground == 0)
					{
						int stout_temp;
						stout_temp=dup(1);
						//printf("in jobs\n");
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

						pinfo(j);

						dup2(stout_temp,STDOUT_FILENO);
						close(stout_temp);
					}
					else if(strcmp(command[j].argval[0],"remindme")==0 && isBackground==0)
					{
						execute_remindme(j);
					}
					else if(strcmp(command[j].argval[0],"clock")==0 && isBackground==0)
					{
						int stout_temp;
						stout_temp=dup(1);
						//printf("in jobs\n");
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
						
						execute_clock(j);

						dup2(stout_temp,STDOUT_FILENO);
						close(stout_temp);
					}
					else if(strcmp(command[j].argval[0],"quit")==0 && isBackground==0)
					{
						function_exit();
					}
					else if(strcmp(command[j].argval[0],"jobs")==0 && isBackground==0)
					{
						int stout_temp;
						stout_temp=dup(1);
						//printf("in jobs\n");
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


						execute_jobs(j);

						dup2(stout_temp,STDOUT_FILENO);
						close(stout_temp);

						//close(INFILE);
						//close(OUTFILE);
					}
					else if(strcmp(command[j].argval[0],"setenv")==0 && isBackground==0)
					{
						execute_setenv(j);
					}
					else if(strcmp(command[j].argval[0],"unsetenv")==0 && isBackground==0)
					{
						execute_unsetenv(j);
					}
					else if(strcmp(command[j].argval[0],"kjob")==0 && isBackground == 0)
					{
						execute_kjob(j);
					}
					else if(strcmp(command[j].argval[0],"fg")==0 && isBackground==0)
					{
						execute_fg(j);
					}
					else if(strcmp(command[j].argval[0],"bg")==0 && isBackground == 0)
					{
						execute_bg(j);
					}
					else if(strcmp(command[j].argval[0],"overkill")==0 && isBackground == 0)
					{
						execute_overkill(j);
					}
					else
					{
						
						if(check_1 == 0 && check_2 == 0)
						{
							//printf("in executble\n");
							executable(j,fd);
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					//printf("in here\n");
					if(check_1 == 0 && check_2 == 0)
					{
						//printf("in executble\n");
						executable(j,fd);
					}
					else
					{
						break;
					}
				}
				
				
					//printf("in\n");
				
				
					
				

				/*}
				else
				{
					//printf("in\n");
					executable(i);
				}*/
				for(int y=0;y<100;y++)	
					memset(command[j].argval[y], 0, sizeof(command[j].argval[y]));
				memset(command[j].full,0,sizeof(command[j].full));


				j++;
			}
			//printf("%d %d outside\n",check_1,check_2);

			if(check_1 == -1)
			{
				//printf("in\n");
				break;
			}
			if(check_2 == -1)
			{
				//printf("in\n");
				break;
			}
			

		}
		int abs;
		ppid=waitpid(-1,&abs,WNOHANG);
		if(ppid!=0 && ppid!=-1)
		{
			if(ppid!=reminder_pid)
			{
				fprintf(stderr,"Process with Pid: %lld has exited with Exit stauts: %d\n",(long long int)ppid,abs);
				delete_job(ppid);
				job_counter--;
			}
			else if(ppid==reminder_pid)
				fprintf(stderr, "Reminder: %s\n",message);
			ppid=0;
		}


	}





	



}
