#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("process begin...\n");
	execlp("ls", "ls", "-l", NULL);
	printf("process end...\n");
	return 0;
}