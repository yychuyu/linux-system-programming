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
		do {
			wpid = waitpid(pid, NULL, WNOHANG);	//使用WNOHANG参数，不会阻塞，直接往下运行
			if (wpid ==0) {
				printf("no child process exit, wait 1s and try again\n");
				sleep(1);	//没有子进程退出，等待1秒再检测
			}
		} while (wpid == 0);
		
		if (wpid == pid) {
			printf("I'm parent process, I catched child process: %d\n", wpid);
		} else {
			printf("other situation...\n");
		}
	}
	return 0;
}