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

int main()
{
   	int qid;

   	int msgkey = ftok("/home/nastya/Documents/key.c", 1);
   	
   	if ((qid = msgget (msgkey, IPC_CREAT| 0666)) == -1)
      		return (-1);
      	
      	struct mymsgbuf msg;
   
   	// Заполняем сообщение произвольными тестовыми данными
   	msg.mtype = 1;  // тип сообщения должен быть положительным)
   	msg.mtext = 0;
   	
      	int all = 0;
      	
      	while (all != 2)
    	{
        	scanf ("%d", &all);
        
        	msg.mtext = all;

        	int  result;

		if((result = msgsnd(qid, &msg, sizeof(int), 0)) == -1)
			return(-1);

    	}
    	while (all == 2)
    		break;
}
