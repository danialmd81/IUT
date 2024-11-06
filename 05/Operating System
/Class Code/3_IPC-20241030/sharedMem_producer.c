#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
// #include <semaphore.h>


int main()
{
    /* the size (in bytes) of shared memory object */
    const int SIZE = 4096;

    /* name of the shared memory object */
    const char *name = "OS1403";
    /* strings written to shared memory */
    const char *message0 = "Hello";
    const char *message1 = "Process!";
    /* shared memory file descriptor */
    int fd;
    /* pointer to shared memory obect */
    char *ptr;
    /* create the shared memory object */
    fd = shm_open(name,O_CREAT | O_RDWR,0666);
    /* configure the size of the shared memory object */
    ftruncate (fd, SIZE);
    /* memory map the shared memory object */
    ptr = (char *)mmap (0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    //sleep(10);
    /* write to the shared memory object */
    sprintf(ptr,"%s",message0);
    ptr += strlen(message0);

    sprintf(ptr,"%s",message1);
    ptr += strlen(message1);
    // while(1)
    //     sleep(1);
    close(fd);

}
