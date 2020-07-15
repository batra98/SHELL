# Cshell
## An Interactive user defined bash-like shell


## :file_folder: Files:

1. shell_2.c
	- Contains the main code for the shell.
2. clear_screen.c
	- Contains the program to clear the screen. It Uses the ASCII character "\e[1;1H\e[2J".
3. exec.c
	- For executing the non builtin commands (both in background and foreground).
4. execute_cd.c
	- Code for implementing cd command. chdir has been used.
5. execute_clock.c
	- Code for implementing clock. sleep has been used.
6. execute_echo.c
	- Code for implementing echo. multi quotes have been handled.
7. execute_ls.c
	- Code for implementing ls,ls -a. path can also be provided.
8. execute_lsl.c
	- Code for implementing ls -al,-la,-l -a,-a -l. (path not supported here).
9. execute_pwd.c
	- Code for implementing pwd.
10. execute_remindme.c
	- Code for implementing reminder. Fork and Waitpid has been used.
11. generate_commandline.c
	- Code for generate commandline. Format = username@systemname:~ (Currently I am printing systemname but if os name is required then it can be done by simply uncommenting some lines of code.)
12. get_input2.c
	- Code for taking input. strtok has been used for tokenizing the string.
13. headers.h
	- Contains all declarations.
14. pinfo.c
	- Code for implementing pinfo.
15. execute_overkill.c
	- kill all background processes.
16. execute_bg.c
	- Starts a process in background which has been stopped.
17. execute_fg.c
	- brings a background process to foreground.
18. delete_job.c
	- remove from job array.
19. execute_setenv.c
	- set env variable.
20. execute_unsetenv.c
	- unset env variable.
21. execute_kjob.c
	- send specific signal to particular bg process.
22. checkOutfile.c
	- checks output file.
23. checkInfile.c
	- checks input file.
24. parse.c
	- parse the command.