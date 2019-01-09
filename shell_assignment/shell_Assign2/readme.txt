											Assignment 2
							Creating an Interactive User Defined Shell

various files:
1 shell_2.c - contains the main code for the shell.
2 clear_screen.c - contains the program to clear the screen. It Uses the ASCII character "\e[1;1H\e[2J".
3 exec.c - for executing the non builtin commands (both in background and foreground).
4 execute_cd - code for implementing cd. chdir has been used.
5 execute_clock - code for implementing clock. sleep has been used.
6 execute_echo - code for implementing echo. multi quotes has been handled.
7 execute_ls - code for implementing ls,ls -a. path can also be provided.
8 execute_lsl - code for implementing ls -al,-la,-l -a,-a -l.
9 execute_pwd - code for implementing pwd.
10 execute_remindme - code for implementing reminder.fork and waitpid has been used.
11 generate_commandline - code for generate commandline. Format = username@systemname:~ (Currently I am printing systemname but if os name is required then it can be done by simply uncommenting some lines of code.)
12 get_input2 - code for taking input.strtok has been used for tokenizing the string.
13 headers.h - contains all declarations.
14 pinfo - code for implementing pinfo.

