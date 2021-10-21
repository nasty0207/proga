#include <pthread.h>
#include <stdio.h>

int main ()
{
	printf("%lu\n", pthread_self());  
}
