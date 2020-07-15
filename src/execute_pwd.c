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

void execute_pwd()
{
	char display_pwd[1000];
	getcwd(display_pwd,1000);
	printf("%s\n",display_pwd);
}