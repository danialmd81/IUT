#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()

{

	pid_t pid;
	int i = 10;
	/* fork a child process */
	pid = fork();
	printf("after fork\n");
	if (pid < 0)
	{ /* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0)
	{ /* child process */
		while (1)
			;
		// for (i; i<20;i++)
		// 	printf("child with pid %d: %d\n", getpid(),i);
		// execlp ("/bin/ls","ls",NULL);
	}
	else
	{ /* parent process */
		printf("child with pid %d is created\n", pid);
		for (i; i < 30; i++)
			printf("parrent with pid %d: %d\n", getpid(), i);

		/* parent will wait for the child to complete */
		// wait(NULL);

		printf("parrent Complete");
	}

	return 0;
}
