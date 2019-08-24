/*
* Message Client
* Takes a string from command line sends it to thre server
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

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("(client)Invalid Number of arguments!\n");
        exit(0);
    }
    //printf("Entered: %s\n", argv[1]);

    struct msgbuf sendBuf;
    int val;
    sendBuf.mtype = 2;
    strcpy(sendBuf.mtext, argv[1]);

    int mqId = msgget(KEY, IPC_CREAT|0600);
    if(mqId < 0) {
        perror("Error in creation of queue!");
        exit(1);
    }

    printf("Created queue, id = %d\n", mqId);
    
    val = msgsnd(mqId, &sendBuf, sizeof(sendBuf.mtext), 0);
     if(val < 0) {
        perror("Error in sending the message!");
        exit(2);
    }
    printf("Sent the message: %s\n", argv[1]);
    printf("Bye!\n");
    
    return 0;
}