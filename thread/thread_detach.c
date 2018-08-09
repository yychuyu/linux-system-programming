#include <stdio.h>
#include <pthread.h>

void *thf(void *arg)
{
	printf("this is a thread\n");
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid;
	int err;
	
	pthread_create(&tid, NULL, thf, NULL);
	pthread_detach(tid);
	err = pthread_join(tid, NULL);
	printf("pthread_join result: %d\n", err);
	return 0;
}