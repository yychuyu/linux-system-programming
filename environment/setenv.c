#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char *name = "ABC";
	char *val = NULL;

	val = getenv(name);
	printf("1. %s = %s\n", name, val == NULL?"NULL":val);

	setenv(name, "hello", 1);
	val = getenv(name);
	printf("2. %s = %s\n", name, val == NULL?"NULL":val);

#if 0
	int ret = unsetenv("ABC");
#else
	int ret = unsetenv("ABC=");
#endif
	printf("ret = %d\n", ret);
	val = getenv(name);
	printf("3. %s = %s\n", name, val == NULL?"NULL":val);

	return 0;
}
