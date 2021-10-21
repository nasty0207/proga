#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main()
{
    	int key = ftok("/home/nastya/Documents/key.c",1);
	int semid = semget(key, 1, 0666 | IPC_CREAT);

    	struct sembuf buf = {0, -1, 0};
	semop (semid, &buf, 1);
	
	printf ("Hello!");
	
	return 0;
}

