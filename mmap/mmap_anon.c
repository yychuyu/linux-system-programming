#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int *p = NULL;
	int pid = 0;
	
	p = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
	if (p == MAP_FAILED) {
		printf("ERROR: mmap failed!\n");
		return -1;
	}
	
	pid = fork();
	if (pid == -1) {
		printf("ERROR: fork failed!\n");
		return -1;
	} else if (pid == 0) {
		/* Child */
		*p = 2000;
		printf("child, p = %d\n", *p);
	} else if (pid > 0) {
		/* Parent */
		sleep(1);
		*p = 5000;
		printf("parent, p = %d\n", *p);
	}
	
	munmap(p, 4);
	return 0;
}