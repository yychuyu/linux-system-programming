#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


#define N 5

int main()
{
	int i = 0;
	pid_t pid, q;
	
	for (i = 0; i < N; i++) {
		/* 循环创建N个子进程 */
		pid = fork();
		if (pid == -1)
			printf("ERROR: fork error!\n");
		else if (pid == 0)
			break;
		
		if (i == 2)
			q = pid;	// 保留第三个子进程的pid
	}
	
	if (i < N) {
		while (1) {
			printf("I'm %dth child process, pid = %d\n", i, getpid());
			sleep(1);
		}
	} else if (i == N) {
		sleep(1);
		printf("I'm parent process\n");
		kill(q, SIGKILL);
		while (1);
	}
	
	return 0;
}