#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int fd = open ("file.FIFO", O_RDWR);
	char *buf = "Hello, world!";
	unsigned int count = strlen(buf);
	int nwritten = write (fd, buf, count);
	
	int bytes; 
   	char *buf_1 = malloc (15);
   	unsigned int count_1 = 15;
   	
   	bytes = read(fd, buf_1, count_1);

	printf("%s\n",buf_1);
   	
   	close (fd);
}
