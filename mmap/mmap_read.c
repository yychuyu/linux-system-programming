#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct
{
	int id;
	char name[20];
	char gender;
}stu;

int main(int argc, char *argv[])
{
	stu *p = NULL;
	int fd = 0;
	
	if (argc < 2) {
		printf("useage: ./a.out file\n");
		return -1;
	}
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("ERROR: open failed!\n");
		return -1;
	}

	p = mmap(NULL, sizeof(stu), PROT_READ, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED) {
		printf("ERROR: mmap failed!\n");
		return -1;
	}
	
	close(fd);
	
	while (1) {
		printf("id = %d, name = %s, gender = %c\n", p->id, p->name, p->gender);
		sleep(2);
	}
	
	munmap(p, sizeof(stu));
	
	return 0;
}