#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

struct msgbuf
{
	long mtype;
	char mtext[100];
};

int main() {

	//Make three processes : parent, child, grandchild.Parent process takes in a text file with instructions in the form(i, j, k) where
//i is either 0, 1, or 2 (0 meaning beginning of file, 1 meaning current position, 2 meaning end of file),
//j being the offset in bytes for the file, and k being the length.
//Parent will send 20 instructions to the child via message passing or shared memory(bonus points for using shared memory path with 10 buffer size),
//child will read instruction of length k,
//then send the string to the grandchild which will print to the console.
//Grandchild concatenates the received text.
	
	//Parent process
	int pid = fork();
	if (pid == 0) {
		//Child process
		int pid2 = fork();
		if (pid2 == 0) {
			//Grandchild process
			//Read from shared memory
			int shmid = shmget(1234, 100, 0666);
			char* str = (char*)shmat(shmid, (void*)0, 0);
			cout << "Grandchild received: " << str << endl;
			shmdt(str);
			shmctl(shmid, IPC_RMID, NULL);
		}
		else {
			//Child process
			//Read from message queue
			int msqid = msgget(1234, 0666);
			struct msgbuf msg;
			msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
			cout << "Child received: " << msg.mtext << endl;
			//Write to shared memory
			int shmid = shmget(1234, 100, 0666 | IPC_CREAT);
			char* str = (char*)shmat(shmid, (void*)0, 0);
			strcpy(str, msg.mtext);
			shmdt(str);
		}
	}
	else {
		//Parent process
		//Write to message queue
		int msqid = msgget(1234, 0666 | IPC_CREAT);
		struct msgbuf msg;
		msg.mtype = 1;
		strcpy(msg.mtext, "Hello");
		msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
	}
	return 0;
}