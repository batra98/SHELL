Cshell : execute_overkill.o execute_kjob.o execute_bg.o execute_fg.o delete_job.o execute_unsetenv.o execute_setenv.o checkOutfile.o checkInfile.o parse.o execute_clock.o clear_screen.o exec.o execute_cd.o execute_remindme.o get_input2.o execute_ls.o pinfo.o execute_echo.o generate_commandline.o execute_pwd.o shell_2.o execute_lsl.o
	gcc -o Cshell execute_overkill.o execute_kjob.o execute_bg.o execute_fg.o delete_job.o execute_unsetenv.o execute_setenv.o checkOutfile.o checkInfile.o parse.o execute_clock.o clear_screen.o exec.o execute_cd.o execute_remindme.o get_input2.o execute_ls.o pinfo.o execute_echo.o generate_commandline.o execute_pwd.o shell_2.o execute_lsl.o

execute_overkill.o : ./src/execute_overkill.c
	gcc -c ./src/execute_overkill.c

execute_kjob.o : ./src/execute_kjob.c
	gcc -c ./src/execute_kjob.c

execute_bg.o : ./src/execute_bg.c
	gcc -c ./src/execute_bg.c

execute_fg.o : ./src/execute_fg.c
	gcc -c ./src/execute_fg.c

delete_job.o : ./src/delete_job.c
	gcc -c ./src/delete_job.c

execute_unsetenv.o : ./src/execute_unsetenv.c
	gcc -c ./src/execute_unsetenv.c

execute_setenv.o : ./src/execute_setenv.c
	gcc -c ./src/execute_setenv.c

checkOutfile.o : ./src/checkOutfile.c
	gcc -c ./src/checkOutfile.c

checkInfile.o : ./src/checkInfile.c
	gcc -c ./src/checkInfile.c

execute_clock.o : ./src/execute_clock.c
	gcc -c ./src/execute_clock.c

clear_screen.o : ./src/clear_screen.c
	gcc -c ./src/clear_screen.c

exec.o : ./src/exec.c
	gcc -c ./src/exec.c

execute_cd.o : ./src/execute_cd.c
	gcc -c ./src/execute_cd.c

execute_remindme.o : ./src/execute_remindme.c
	gcc -c ./src/execute_remindme.c

get_input2.o : ./src/get_input2.c
	gcc -c ./src/get_input2.c

execute_ls.o : ./src/execute_ls.c
	gcc -c ./src/execute_ls.c

execute_lsl.o : ./src/execute_lsl.c
	gcc -c ./src/execute_lsl.c	

pinfo.o : ./src/pinfo.c
	gcc -c ./src/pinfo.c

execute_echo.o : ./src/execute_echo.c
	gcc -c ./src/execute_echo.c

generate_commandline.o : ./src/generate_commandline.c
	gcc -c ./src/generate_commandline.c

execute_pwd.o : ./src/execute_pwd.c
	gcc -c ./src/execute_pwd.c

parse.o : ./src/parse.c
	gcc -c ./src/parse.c

shell_2.o : ./src/shell_2.c
	gcc -c ./src/shell_2.c

clean : 
	rm -f execute_overkill.o execute_kjob.o execute_bg.o execute_fg.o delete_job.o execute_unsetenv.o execute_setenv.o checkOutfile.o checkInfile.o parse.o execute_clock.o clear_screen.o exec.o execute_cd.o execute_remindme.o get_input2.o execute_ls.o pinfo.o execute_echo.o generate_commandline.o execute_pwd.o shell_2.o execute_lsl.o Cshell