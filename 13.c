#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>
#include <stdio.h>

int main ()
{
	unsigned int key = ftok ("/home/nastya/Documents/key.c", 1);
	int i = shmget(key,1024,0777|IPC_CREAT|IPC_EXCL);
	char *array;
	array = shmat(i, NULL, 0);
	char* buff = (char*)array;
	while (1==1)
	{
		puts (array);
		printf("%s", buff);
		
		if (!strcmp (array, "Goodbye"))
			break;
	}
	return 0;
	
}
