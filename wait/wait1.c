#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid, wpid;
	
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		/* 子进程 */
		printf("I'm child process, pid = %d, going to exit in 3s\n", getpid());
		sleep(3);
	} else if (pid > 0) {
		/* 父进程 */
		printf("I'm parent process, going to wait the child process\n");
		/* 调用wait函数后，父进程将在此死等，直到子进程退出 */
		wpid = wait(NULL);	//如果不关心子进程的退出状态，只是想将子进程回收，那么status参数传NULL即可
		printf("I'm parent process, I catched child process: %d\n", wpid);
	}
	return 0;
}