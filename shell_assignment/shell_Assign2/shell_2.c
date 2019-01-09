#include "headers.h"

void function_exit()
{
    exit_flag = 1;
    return;
}



int main(int argc, char *argv[])
{
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
	
	while(exit_flag==0)
	{
		generate_commandline();

		getinput_2();
		//printf("%s\n",args[0]);
		//printf("%d\n",strcmp(args[0],"cd"));

		for(int i=0;i<comm_size;i++)
		{
			for(int j=0;j<command[i].argcount;j++)
			{
				if(strcmp(command[i].argval[j],"&")==0)
				{
					isBackground=1;
				}
			}
			/*if(isBackground == 0)
			{*/
			if(strcmp(command[i].argval[0],"cd")==0 && isBackground == 0)
			{
				execute_cd(i);
			}
			else if(strcmp(command[i].argval[0],"pwd")==0 && isBackground == 0)
			{
				execute_pwd();
			}
			else if(strcmp(command[i].argval[0],"echo")==0 && isBackground == 0)
			{
				execute_echo(i);
			}
			else if(strcmp(command[i].argval[0],"ls")==0 && isBackground==0)
			{
				if(command[i].argcount==1)
				{
					execute_ls(1,i);
				}
				else
				{
					if(strcmp(command[i].argval[1],"-a")==0)
					{
						if(strcmp(command[i].argval[2],"-l")!=0)
							execute_ls(2,i);
						else
							execute_lsl(2,i);
					}
					else if(strcmp(command[i].argval[1],"-l")==0)
					{
						if(strcmp(command[i].argval[2],"-a")!=0)
						{
								//printf("in\n");
							execute_lsl(1,i);
						}
						else
							execute_lsl(2,i);
					}
					else if(strcmp(command[i].argval[1],"-la")==0 || strcmp(command[i].argval[1],"-al")==0)
					{
						execute_lsl(2,i);
					}
					else
					{
						execute_ls(1,i);
					}
				}

			}
			else if(strcmp(command[i].argval[0],"pinfo")==0 && isBackground == 0)
			{
				pinfo(i);
			}
			else if(strcmp(command[i].argval[0],"remindme")==0 && isBackground==0)
			{
				execute_remindme(i);
			}
			else if(strcmp(command[i].argval[0],"clock")==0 && isBackground==0)
			{
				execute_clock(i);
			}
			else if(strcmp(command[i].argval[0],"exit")==0 && isBackground==0)
			{
				function_exit();
			}
			else
			{
					//printf("in\n");
				executable(i);
			}

			/*}
			else
			{
				//printf("in\n");
				executable(i);
			}*/
			for(int y=0;y<100;y++)	
				memset(command[i].argval[y], 0, sizeof(command[i].argval[y]));
			memset(command[i].full,0,sizeof(command[i].full));	


		}
		int abs;
		ppid=waitpid(-1,&abs,WNOHANG);
		if(ppid!=0 && ppid!=-1)
		{
			if(ppid!=reminder_pid)
				fprintf(stderr,"Process with Pid: %lld has exited with Exit stauts: %d\n",(long long int)ppid,abs);
			else if(ppid==reminder_pid)
				fprintf(stderr, "Reminder: %s\n",message);
			ppid=0;
		}


	}





	



}
