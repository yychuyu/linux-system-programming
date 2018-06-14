#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define NORMALEXIT 0

int main()
{
	pid_t pid, wpid;
	int status;
	
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(1);
	} else if (pid == 0) {
		/* 子进程 */
#if NORMALEXIT
		/* 子进程正常退出的情况 */
		printf("I'm child process, pid = %d, going to exit in 3s\n", getpid());
		sleep(3);
		exit(10);
#else
		/* 子进程异常退出的情况 */
		execl("./abnormal", "abnormal", NULL);
		perror("execl");
		exit(11);
#endif
	} else if (pid > 0) {
		/* 父进程 */
		printf("I'm parent process, going to wait the child process\n");
		wpid = wait(&status);	//使用status接收子进程的退出状态
		if (WIFEXITED(status)) {	//如果子进程正常退出，则WIFEXITED宏函数返回真
			printf("I'm parent process, child process: %d exit normally with return value: %d\n", 
				wpid, WEXITSTATUS(status));		//使用WEXITSTATUS获取进程退出状态（exit的参数）
		} else if (WIFSIGNALED(status)) {
			printf("I'm parent process, child process: %d is killed by signal: %d\n", 
				wpid, WTERMSIG(status));	//使用WTERMSIG获取使子进程终止的那个信号的编号
		}

	}
	return 0;
}