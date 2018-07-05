#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void printPending(sigset_t *set)
{
	int i = 0;
	
	for (i = 0; i < 32; i++) {
		if (sigismember(set, i) == 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

int main()
{
	sigset_t set, oldset, pendset;
	sigemptyset(&set);
	sigaddset(&set, SIGQUIT);	// ctrl + \ 将产生SIGQUIT信号
	sigprocmask(SIG_BLOCK, &set, &oldset);
	while (1) {
		sigpending(&pendset);
		printPending(&pendset);		// 写一个函数打印未决信号集
		sleep(1);
	}
}