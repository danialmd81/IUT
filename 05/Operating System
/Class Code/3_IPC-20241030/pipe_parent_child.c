/*
making a pipe between parent and child, sending messages from parent to child
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
   int fd[2];
   char buffer[256];
   int x = pipe(fd);
   printf("parent: fd[0]=%d, fd[1]=%d\n", fd[0], fd[1]);
   pid_t pid, pid2;
   pid=fork();
   if(pid==0) //in child
   {
     pid2 = fork();
     if(pid2==0){
      close(fd[1]);
      printf("child: fd[0]=%d, fd[1]=%d\n", fd[0], fd[1]);
      // sleep(20);
      printf("child \n");
      while(1)
      {
          char buffer2[256];
          //sleep(2);  
          // read(fd[0],buffer,255);
          if (read(fd[0],buffer,255)>0){
            printf("child: reading a msg from parent: %s\n", buffer);
            //printf("child: %s\n",buffer);
          }
          else{
            printf("child: nothing to display\n");
            break;
          // sprintf(buffer2,"message to parent");
          // sleep(2);
          // write(fd[1],buffer2,255);
          }
      }
     }
   }
   else// in parent
   {
    int i = 5;
    close(fd[0]);
    printf("parent\n");
    while(i>0)
    {
        sleep(2);
        char buffer2[256];
        sprintf(buffer2,"hello child %d", i);
        printf("parent: sending a msg to child\n");
        write(fd[1],buffer2,255);
        // if (read(fd[0],buffer,255)>0){
        //    printf("parent: reading a msg in parent: %s\n", buffer);
        
        // }
        // read(fd[0], buffer2,255);
        // printf("%s\n", buffer2);
        i--;
    }
    close(fd[1]);
    wait(NULL);
    
  }

return 0;
}
