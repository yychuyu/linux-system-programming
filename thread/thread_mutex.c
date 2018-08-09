#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *tfn(void *arg)
{
	srand(time(NULL));

	while(1) {
		pthread_mutex_lock(&mutex);
		printf("hello ");			// 标准输出为共享资源
		sleep(rand() % 3);			// 在此时会失去CPU
		printf("world!\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 3);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	int n = 5;
	
	srand(time(NULL));

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&tid, NULL, tfn, NULL);

	while(n--) {
		pthread_mutex_lock(&mutex);
		printf("HELLO ");
		sleep(rand() % 3);
		printf("WORLD!\n");
		pthread_mutex_unlock(&mutex);
		sleep(rand() % 3);
	}
	
	pthread_cancel(tid);
	pthread_join(tid, NULL);
	
	pthread_mutex_destroy(&mutex);
	return 0;
}