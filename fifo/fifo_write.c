#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "./myfifo"

int main()
{
	int res = 0;
	int fd;
	char *data = "hello world!";

	if (access(FIFO_NAME, F_OK) == -1) {	// 检测FIFO是否存在
		res = mkfifo(FIFO_NAME, 0777);		// 若不存在，则创建FIFO
		if (res != 0) {
			printf("ERROR: fifo make error!\n");
			return -1;
		}
	}
	
	fd = open(FIFO_NAME, O_WRONLY);		// 打开FIFO
	if (fd == -1) {
		printf("ERROR: fifo open error!\n");
		return -1;
	}
	
	while (1) {
		ssize_t len = write(fd, data, strlen(data));	// 写FIFO
		if (len != strlen(data)) {
			printf("ERROR: pipe write error!\n");
			return -1;
		}
		printf("pipe write: %s\n", data);
		sleep(1);
	}
	close(fd);
	return 0;
}