#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct mymsgbuf 
{
      long mtype;
      int mtext;  
};


int main ()
{
   	int msgkey = ftok ("/home/nastya/Documents/key.c", 1);
	
    	int qid = msgget (msgkey, IPC_CREAT | 0666);
	
	struct mymsgbuf msg;
	
	msg.mtext = 0;
    	
    	while (msg.mtext != 2)
    {
        msgrcv (qid, &msg, sizeof(int), 1, 0);
        printf ("%d\n", msg.mtext);
    }
}
