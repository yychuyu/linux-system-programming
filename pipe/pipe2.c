#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main ()
{
	int fd[2];
	int i = 0;
	pid_t pid;
	char buf[1024];
	char *data = "hello world!";
	
	/* 创建管道 */
	if (pipe(fd) == -1) {
		printf("ERROR: pipe create failed!\n");
		return -1;
	}
	
	for (i = 0; i < 2; i++) {
		pid = fork();
		if (pid == -1) {
			printf("ERROR: fork error!\n");
			return -1;
		} else if (pid == 0) {
			break;
		}
	}
	
	/* 通过i来判断创建的子进程及父进程 */
	if (i == 0) {
		/* 第一个子进程，兄进程 */
		close(fd[0]);	// 兄进程向弟进程写数据，关闭读端
		write(fd[1], data, strlen(data));
		printf("elder brother send: %s\n", data);
		close(fd[1]);
	} else if (i == 1) {
		/* 第二个子进程，弟进程 */
		close(fd[1]);
		read(fd[0], buf, sizeof(buf));
		printf("younger brother receive: %s\n", buf);
		close(fd[0]);
	} else {
		/* 父进程 */
		close(fd[0]);
		close(fd[1]);
		for (i = 0; i < 2; i++) {
			wait(NULL);
		}
	}
	
	return 0;
}