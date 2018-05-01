#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int var = 10;

int main()
{
	pid_t pid = 0;
	pid = fork();
	if (pid == -1) {
		perror("fork");
		return -1;
	} else if (pid > 0) {
		/* 父进程 */
		sleep(1);
		var = 20;
		printf("I'm parent, pid = %d, parentID = %d, var = %d\n", getpid(), getppid(), var);
	} else if (pid == 0) {
		/* 子进程 */
		var = 30;
		printf("I'm child, pid = %d, parentID = %d, var = %d\n", getpid(), getppid(), var);
	}
	printf("var = %d\n", var);
	return 0;
}
