# Cshell
## An Interactive user defined bash-like shell

## About the shell
**Cshell** is an interactive user defined bash-like shell that supports semi-colon separated list of commands.

## :file_folder: File-Structure
```bash
.
├── LICENSE
├── Makefile
├── README.md
└── src

1 directory, 3 files
```
- **src** - This directory contains all the .c files for the various commands. More information about each file is present in the directory.

## :running: How to execute the shell

- Compile the .c files using the following command.
```bash
make Cshell
```
- Run the shell using the following command.
```bash
./Cshell
```
- To exit the shell, use the following command.
```bash
quit
```
- On executing the shell, A command line is generated of the format: **username@systemname:~**.

## List of commands along with flags.

| Command | Description | Flags | Usage | Number of Arguments |
| :---: | :---: | :---: | :---: |:---: |
| ls | Lists the files and directories present. | [la] | ls -[la] [path] | 0 or 1 (path to the directory) |
| pwd | Prints the path of the current directory | - | pwd | - |
| cd | Change Directory | - | cd [path] | 1 (path to the directory) |
| echo | Print on terminal | - | echo [message] | 0 or more (message to be printed) |
| pinfo | Display the process info of the given process id | - | pinfo [process id] | 0 or more (process id) |
| clock | Displays dynamic date and time | [t][a] | clock -t [2] -n [3] | 2 (displays time after [t] seconds [n] times) |
| remindme | Set a reminder for the time given | - | remindme [time] [message] | 1 or 2 (displays [message after [time] seconds]) |
| setenv | Can be used to create/change environment variables | - | setenv [var_name] [value] | 1 or 2 (sets the environment variable [var_name] to [value]) |
| unsetenv | Can be used to remove environment variables | - | unsetenv [var_name] | 1 (unsets the environment variable [var_name]) |
| jobs | Lists the background processes with status | - | jobs | - |
| kjob | Kill the process listed in jobs | - | kjob -[9] [job_id] | 2 (signal to send and [job_id]) |
| overkill | Kill all background processes | - | overkill | - |
| fg | Bring a background process to foreground | - | fg [job_id] | 1 ([job_id] of the background process) |
| bg | Used to restart a stopped background process | - | bg [job_id] | 1 ([job_id] of the background process) |
| quit | Used to exit the shell | - | quit | - |

## Features
- Supports semi-colon separated commands.
- Background processes can be created by appending **&** to the command.
- Supports input and output file redirection.
- Supports piping of commands.
- Supports signals like **Ctrl+Z** , **Ctrl+C**.

______________________________________________

Feel free to contribute. :heart:


