#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;

	for (int i = 0; i < 2; i++)
	{
		pid = fork();
		if (pid > 0)
		{
			fork();
			execlp("ls", "ls", "-l", (char*)NULL);
			printf("Parent process (PID: %d) waiting for child process (PID: %d) to complete\n", getpid(), pid);
			wait(&status);
		}
		if (pid < 0)
		{ // Fork failed
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}