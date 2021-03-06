#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        while (1) {
			/* 子进程死循环，保证不死 */
            printf("I am child, my parent pid = %d\n", getppid());
            sleep(1);
        }
    } else if (pid > 0) {
			/* 父进程睡眠3秒后退出 */
            printf("I am parent, my pid is = %d\n", getpid());
            sleep(3);
            printf("------------parent going to die------------\n");
    } else {
        perror("fork");
        return 1;
    }
    return 0;
}