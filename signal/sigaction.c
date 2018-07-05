#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void func(int signal)
{
	printf("SIGQUIT catched!\n");
	sleep(2);	//用来模拟回调函数执行很长时间
	printf("func finished!\n");
}

int main()
{
	struct sigaction act;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);	//先清空临时阻塞信号集
	sigaddset(&act.sa_mask, SIGINT);	// 执行回调函数期间，屏蔽SIGINT
	act.sa_flags = 0;
	
	sigaction(SIGQUIT, &act, NULL);	//注册回调函数
	
	while(1);
	
	return 0;
}