#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *my_getenv(const char *name)
{
	int i = 0;
	char *p = NULL;
	
	if (name == NULL)
		return NULL;
	
	for (i = 0; environ[i] != NULL; i++) {
		p = strstr(environ[i], "=");
		if (strncmp(environ[i], name, p - environ[i]) == 0)
			return p + 1;
	}
	return NULL;
}

int main(int argc, char **argv)
{
	char *p = NULL;

	if (argc != 2) {
		printf("usage: ./getenv name\n");
		return -1;
	}

	p = my_getenv(argv[1]);
	if (p == NULL)
		printf("no match!\n");
	else
		printf("%s\n", p);

	return 0;
}
