#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stddef.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t p_1;

void *threadfunc (void *arg)
{
	printf ("Третий тред: %lu\n", p_1);
	return NULL;	
}
	
int main ()
{
	int n = 0;
	printf ("Введите количество трейдов, который вы хотите запустить: ");
	scanf ("%d", n);
	printf ("Четвертый тред: %lu \n", pthread_self());
	pthread_create(&p_1, NULL, threadfunc, NULL);
	pthread_join(p_1, NULL);
	unsigned int key = ftok ("/home/nastya/Documents/key.c", 1);
	int i = shmget(key,1024,0777|IPC_CREAT|IPC_EXCL);
	int *array;
	if(i != -1)
	{
        	array = shmat(i, NULL, 0);
        	array[0] = 0;
        	array[1] = 0;
        	array[2] = 0;
        	array[3] = 0;
        	array[4] = 0;
    	} 
    	else
    	{	
        	int i_1 = shmget (key, 1024, 0777);
        	array = shmat (i_1, NULL, 0);
        	
        	if ( n == 2)
        	{ 
        		array[0] += 1;
        		array[1] += 1;
        		array[4] += 1;
        	}
 		
 		if ( n == 1)
        	{ 
        		array[0] += 1;
        		array[1] += 0;
        		array[4] += 1;
        	}
    	     	
    	     	if ( n == 0)
        	{ 
        		array[0] += 0;
        		array[1] += 0;
        		array[4] += 0;
        	}

     	}
    	printf("Тред 1: %d раз, Тред 2: %d раз, Тред 3: %d раз, Тред 4: %d раз, Всего: %d раз\n",array[0], array[1], array[2], array[3], array[4]);
	shmdt (&array);
	return 0;
}

