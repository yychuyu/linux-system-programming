#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

unsigned int my_alarm(unsigned int sec)
{
	struct itimerval new_value, old_value;
	int ret = -1;
	
	new_value.it_value.tv_sec = sec;
	new_value.it_value.tv_usec = 0;
	new_value.it_interval.tv_sec = 0;
	new_value.it_interval.tv_usec = 0;
	
	ret = setitimer(ITIMER_REAL, &new_value, &old_value);
	if (ret == -1) {
		printf("ERROR: setitimer error!\n");
		exit(1);
	}
	return old_value.it_value.tv_sec;
}

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