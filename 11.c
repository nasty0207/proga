#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int fd = open ("../file.FIFO", O_RDWR);
	int bytes; 
   	char *buf = malloc (1024);
	int count = 1024;
	
	while (1==1)
	{	
		bytes = read(fd, buf, count);
		puts (buf);
		if (!strcmp(buf, "Goodbye"))
			break;
   	}
   	
   	close (fd);
   	return 0;
}
