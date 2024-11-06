#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
// #include <semaphore.h>

int main()
{
	/* the size (in bytes) of shared memory object */
	const int SIZE = 4096;
	
	/* name of the shared memory object */
	const char *name = "OS1403";
	/* shared memory file descriptor */
	int fd;
	/* pointer to shared memory obect */
	char *ptr;
	/* open the shared memory object */
	fd = shm_open (name, O_RDWR, 0666);
	/* memory map the shared memory object */
	ptr = (char *)mmap (0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	/* read from the shared memory object */
	printf("%s\n",ptr);
	/* remove the shared memory object */
	// shm_unlink (name);
	close(fd);
}
