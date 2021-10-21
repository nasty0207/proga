#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
int main()
{
	int semid;
	key_t key; /* IPC ключ */ 
	struct sembuf buf;
	if((key = ftok("/home/nastya/Documents/key.c",0)) < 0)
	{
		printf("Can\'t generate key\n");
	}
	semid = semget(key, 1, 0777 | IPC_CREAT);
	/* Выполним операцию D(semid1,1), для этого сначала заполним нашу структуру. Наш массив семафоров состоит из одного семафора с номером 0. Код операции -1.*/
	buf.sem_op = -1;
	buf.sem_flg = 0;
	buf.sem_num = 0;
	semop(semid, &buf, 1);
	printf ("%d", semid);
	return 0;
}
