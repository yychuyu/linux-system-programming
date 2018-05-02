#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("process begin...\n");
	char *envp[] = {"AA=11", "BB=22", NULL};
	execle("./env", "env", NULL, envp);
	printf("process end...\n");
	return 0;
}