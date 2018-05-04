#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    pid = fork();
    if (pid == 0) {
            printf("I am child, my parent= %d, going to sleep 3s\n", getppid());
            sleep(3);
            printf("-------------child die--------------\n");
    } else if (pid > 0) {
            printf("I am parent, pid = %d, myson = %d, going to sleep 5s\n", getpid(), pid);
            sleep(5);
			system("ps -o pid,ppid,state,tty,command");
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}