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

int main()
{
   	int qid;

   	int msgkey = ftok("/home/nastya/Documents/key.c", 1);
	//printf ("%d", msgkey);
   	
   	if ((qid = msgget (msgkey, IPC_CREAT| 0666)) == -1)
      		return (-1);
      	//printf ("%d\n", qid);
      	struct mymsgbuf msg;
   
   	// Заполняем сообщение произвольными тестовыми данными
   	msg.mtype = 1;  // тип сообщения должен быть положительным)
   	
   	scanf("%s", msg.mtext);
 
   	int  result;

	if((result = msgsnd(qid, &msg, 256, 0)) == -1)
		return(-1);

}
