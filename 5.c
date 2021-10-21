#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main (){
	pid_t a = 0;
	a = fork ();
	if (a == 0)
		printf ("Я ребенок: %u %u\n", getppid(), getpid());
	else
		printf ("Я взрослый: %u %u\n", a, getppid());

}

