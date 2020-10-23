#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char * argv[]) {
	pid_t pid; 
	if((pid = fork()) != 0)
	{
		int status;
		//pid: chiamata del fork
		//getpid: ritorna il tuo pid
		//getppid: ritorna il pid del padre
		printf("genitore %d %d %d\n", pid, getpid(), getppid());
		waitpid(pid, &status, 0);
		printf("exit status %d \n", WEXITSTATUS(status));
		_exit(0);
	}
	else
	{
		//pid: perché è un figlio
		//getpid: =pid del padre
		//getppid: =getpid del padre
		printf("figlio   %d     %d %d\n", pid, getpid(), getppid());
		sleep(1);
		_exit(44);
	}
}
