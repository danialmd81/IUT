/*
making a pipe between parent and child and sending messages from parent to child
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
    int pipe;
    int tmp;
    char path[20];
    sprintf(path,"2.pipe");
   
    //making the named-pipe
    mkfifo(path,0777);
    char buffer[256];
    bzero(buffer,256);
    tmp=0;
    // printf("line 23\n");
    //pipe=open(path,O_WRONLY);
    pipe=open(path,O_RDWR);
   // sleep(10);
    while(1)
    {
        sprintf(buffer,"%d",tmp);
        tmp++;
        printf("+parent -> %s", buffer);
        write(pipe,buffer,strlen(buffer));
        sleep(1);
    }
    return 0;
}
