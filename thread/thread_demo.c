#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int var = 100;

void *tfn(void *arg)
{
	var = 200;

	printf("this is a thread, tid: %lu\n", pthread_self());	// 使用pthread_self获取线程号
	printf("the arg is: %d\n", *(int *)arg);	// arg强转回整形
	printf("var changed in thread: %d\n", var);	// 同一进程内全局变量共享
	pthread_exit(NULL);		//线程退出使用pthread_exit
	return NULL;
}

int main()
{
	pthread_t tid;
	int arg = 5;

	printf("this is main, pid: %d\n", getpid());	// 获取进程号使用getpid
	pthread_create(&tid, NULL, tfn, (void *)&arg);	// 使用arg传递参数到线程主函数
	sleep(1);	// 睡眠1秒是为了保证线程能有机会执行
	return 0;
}