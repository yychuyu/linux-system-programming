#include <stdio.h>
#include <signal.h>

void func()
{
	printf("SIGQUIT catched!\n");
}

int main()
{
	signal(SIGQUIT, func);
	while(1);
}
