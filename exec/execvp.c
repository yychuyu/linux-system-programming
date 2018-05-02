#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("process begin...\n");
	char *argv[] = {"ls", "-a", "-l", NULL};
	execvp("ls", argv);
	printf("process end...\n");
	return 0;
}