#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv, char **env){
	execl ("/bin/ls","/bin/ls","/home/nasty/Documents/", NULL);
}
