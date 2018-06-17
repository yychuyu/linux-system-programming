#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	int len = 0;
	char *p = NULL;
	char *data = "hello world!";
	
	fd = open("./test.txt", O_RDWR);
	if (fd == -1) {
		printf("ERROR: open error!\n");
		return -1;
	}
	
	len = lseek(fd, 0, SEEK_END);	// 计算文件大小
	
	p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (p == MAP_FAILED) {			// 这里不是p == NULL
		printf("ERROR: mmap failed!\n");
		return -1;
	}
	
	close(fd);
	
	strcpy(p, data);			//向共享内存写数据
	printf("data = %s\n", p);	//向共享内存读数据
	
	munmap(p, len);
	
	return 0;
}