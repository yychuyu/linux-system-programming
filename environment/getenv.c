#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char **argv)
{
	char *p = NULL;

	if (argc != 2) {
		printf("usage: ./getenv name\n");
		return -1;
	}

	p = getenv(argv[1]);
	if (p == NULL)
		printf("no match!\n");
	else
		printf("%s\n", p);

	return 0;
}
