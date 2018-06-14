#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd[2];
	pid_t pid;
	char buf[1024];
	char *data = "hello world!";
	
	/* 创建管道 */
	if (pipe(fd) == -1) {
		printf("ERROR: pipe create failed!\n");
		return -1;
	}
	
	pid = fork();
	if (pid == 0) {
		/* 子进程 */
		close(fd[1]);	// 子进程读取数据，关闭写端
		read(fd[0], buf, sizeof(buf));	// 从管道读数据
		printf("child process read: %s\n", buf);
		close(fd[0]);
	} else if (pid > 0) {
		/* 父进程 */
		close(fd[0]);	//父进程写数据，关闭读端
		write(fd[1], data, strlen(data));	// 向管道写数据
		printf("parent process write: %s\n", data);
		close(fd[1]);
	}
	
	return 0;
}