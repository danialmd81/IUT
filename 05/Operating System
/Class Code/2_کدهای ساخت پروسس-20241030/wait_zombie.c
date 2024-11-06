#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()

{

	pid_t pid;
	int i = 0;
	int status;
	/* fork a child process */
	pid= fork ();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) { /* child process */
		
		for (i; i<10;i++)
			printf("child: child with pid %d: %d\n", getpid(),i);
		exit(10);
        //execlp ("/bin/ls","ls",NULL);
	}
	else { /* parent process */
		printf("parent: child with pid %d is created\n", pid);
		//for creating a zombie sleep parent
		sleep(20);
		for (i; i<10;i++)
			printf("parent: parent with pid %d: %d\n", getpid(),i);

		/* parent will wait for the child to complete */
		
		
		// pid_t return_pid = wait(&status);
		// printf("parent: child with pid %d is finished with exit status %d\n", return_pid, WEXITSTATUS(status));
		// if(WIFEXITED(status))
		//     printf("parrent: Child process returned normally\n");
		// if(WIFSIGNALED(status))
		//     printf("parrent: Child process terminated by signal\n");
		
		printf("parent: parent Completed\n");
	}
	
	return 0;
}

