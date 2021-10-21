#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main (){
	 int a = 0;	
         a =  fork();
	 printf ("Hello world!\n %u", a);
	 return 0;


}

