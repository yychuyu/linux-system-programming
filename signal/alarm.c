#include <stdio.h>
#include <unistd.h>

int main()
{
	unsigned int t = 0;
	printf("process start..\n");
	alarm(10);
	sleep(2);
	t = alarm(2);
	printf("time left: %d\n", t);
	while (1);	// 进程停在此处，直到收到定时器信号SIGALRM将进程杀死
	
	return 0;
}