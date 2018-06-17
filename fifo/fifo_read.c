#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "./myfifo"

int main()
{
	int res = 0;
	int fd;
	char buf[1024] = {0};

	if (access(FIFO_NAME, F_OK) == -1) {	// 检测FIFO是否存在
		res = mkfifo(FIFO_NAME, 0777);		// 若不存在，则创建FIFO
		if (res != 0) {
			printf("ERROR: fifo make error!\n");
			return -1;
		}
	}

	fd = open(FIFO_NAME, O_RDONLY);		// 打开FIFO
	if (fd == -1) {
		printf("ERROR: fifo open error!\n");
		return -1;
	}

	while (1) {
		ssize_t len = read(fd, buf, sizeof(buf));	// 读FIFO
		if (len < 0) {
			printf("ERROR: pipe read error!\n");
			return -1;
		}
		printf("pipe read: %s\n", buf);
	}
	close(fd);
	return 0;
}