/*
* Message Server -- Process Based
*/

#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define KEY 1234

struct msgbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[10];    /* message data */
};

int main() {
    struct msgbuf rxBuf;
    int val;
    int count = 0;
    struct msqid_ds test;
    
    int mqId = msgget(KEY, IPC_CREAT|0600);
    if(mqId < 0) {
        printf("Error while Creating the mq!");
        exit(1);
    }

    printf("Starting Server(%d)!!\n", mqId);
   
   // Keep on continously Checking 
    while(1) {
        val = msgrcv(mqId, &rxBuf, sizeof(rxBuf.mtext), 2, 0);
    
        if(val < 0) {
            perror("Error in recieving the message!");
            exit(1);
        } else {
            count++;
            printf("(Server)recieved(count = %d): type = %d, msg = %s\n", count, rxBuf.mtype, rxBuf.mtext);
        }
    }

    msgctl(mqId, IPC_RMID, &test);
    printf("Shutting down Server!\n");
    return 0;
}