#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int pipe;
    int tmp;
    char path[20];
    sprintf(path,"2.pipe");
    
    //making the named-pipe
    //mkfifo(path,0777);
    char buffer[256];
    bzero(buffer,256);
    /*
    operations on named-pipe are similar to a file
    we open the named-pipe
    */
    //pipe=open(path,O_RDONLY|O_NONBLOCK);
    pipe=open(path,O_RDONLY);
    while(1){
      read(pipe,buffer,255);
      printf("**child <- %s\n",buffer);
      bzero(buffer,256);
      sleep(1);
    }
}
