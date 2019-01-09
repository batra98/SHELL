#ifndef headers
#define headers

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



const char *user_name;
struct utsname unameData;
char command_line[1000];
char home[1000];
char current[1000];
int exit_flag;
char* args[100];
int argcount;
char *input;
char *input_1;
char *input_2;
char *temp;
char *echo_arr;
struct dirent **list;
char *curr;
long long int comm_size;
int isBackground;
pid_t ppid;

struct _instr
{
	char full[100];
    char argval[100][25];
    int argcount;
};
typedef struct _instr instruction;
instruction command[100];
pid_t reminder_pid;
int time_remind;
char message[1000];
char host[1000];

void execute_remindme(int);
void pinfo(int);
void execute_lsl(int,int);
void execute_ls(int,int);
void execute_echo(int);
void execute_pwd();
void execute_cd(int);
void getinput_2();
void clear_screen();
void generate_commandline();
void executable(int);
void execute_clock(int);


#endif