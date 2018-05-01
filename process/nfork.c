#include <stdio.h>
#include <unistd.h>

#define CHILDNUM 5

int main(int argc, char **argv)
{
	int i = 0;
	for (i = 0; i < CHILDNUM; i++) {
		/* 如果是子进程，即fork返回值是0，则直接退出循环，
		 * 避免裂变 */
		if (fork() == 0)
			break;
	}

	if (i == CHILDNUM) {
		/* 父进程会进入此代码块，睡眠CHILDNUM秒，保证最后一个打印信息 */
		sleep(CHILDNUM);
		printf("I'm parent, pid = %d\n", getpid());
	} else {
		/* 子进程会进入此代码块，睡眠i秒再打印信息 */
		sleep(i);
		printf("I'm %dth child, pid = %d\n", i + 1, getpid());
	}
	return 0;
}
