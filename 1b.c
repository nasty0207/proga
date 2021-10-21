#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mymsgbuf 
{
      long mtype;     
      char mtext [256];   
};


int main ()
{
   	int msgkey = ftok ("/home/nastya/Documents/key.c", 1);
	//printf ("%d", msgkey);

    	int qid = msgget (msgkey, IPC_CREAT | 0666);
	//printf ("%d\n", qid);
    	struct mymsgbuf msg;

    	int a = msgrcv (qid, &msg, 256, 1, 0);
    	printf ("%d", a);
    	
    	printf ("%s\n", msg.mtext);
}
