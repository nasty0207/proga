#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main ()
{
	umask (0);
	mknod ("file.FIFO", S_IFIFO|0777,0);
	return 0;
}

