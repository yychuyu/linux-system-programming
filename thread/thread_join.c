#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int age;
} stu_t;

void *tfn(void *arg)
{
	stu_t *student = (stu_t *)malloc(sizeof(stu_t));
	if (student == NULL) {
		printf("malloc failed!\n");
		pthread_exit((void *)(-1));
	}
	
	memset(student, 0, sizeof(stu_t));
	student->age = 20;
	memcpy(student->name, "Harry", strlen("Harry"));
	printf("This is a thread!\n");
	pthread_exit((void *)student);
	return NULL;
}

int main()
{
	pthread_t tid;
	stu_t *ret;
	
	pthread_create(&tid, NULL, tfn, NULL);
	pthread_join(tid, (void **)&ret);
	printf("This main thread, ret->name: %s, ret->age: %d\n", ret->name, ret->age);
	
	return 0;
}