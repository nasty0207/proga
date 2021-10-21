#include <pthread.h>
#include <stdio.h>

int i = 0;
pthread_t p_1;

void *threadfunc (void *arg)
{
	i = i + 1;
	printf ("Первый тред: %lu\n", p_1);
	printf (" i = %d\n", i); 
	return NULL;
	
}

pthread_t p_3;
int o = 0;

void *threadfunc_1 (void *arg)
{
	printf ("Третий тред: %lu\n", p_3);
	o = o + 1;
	printf (" o = %d\n", o); 
	return NULL;
	
}


int main ()
{
	printf ("Второй тред: %lu \n", pthread_self());
	
	pthread_create(&p_1, NULL, threadfunc, NULL);
	printf ("Первый тред: %lu\n", p_1);
	i = i + 1;
	printf (" i = %d\n", i);
	pthread_join(p_1, NULL);
	
	pthread_create(&p_3, NULL, threadfunc_1, NULL);
	printf ("Третий тред: %lu\n", p_3);
	o = o + 1;
	printf (" o = %d\n", o);
	pthread_join(p_3, NULL);
	return 0;
}
