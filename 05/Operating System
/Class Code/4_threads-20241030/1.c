#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;

	// Fork a child process
	pid = fork();

	if (pid < 0)
	{ // Fork failed
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{ // Child process
		printf("Child process (PID: %d) executing 'ls -l'\n", getpid());

		// Replace the child process with the "ls -l" command
		execlp("ls", "ls", "-l", (char*)NULL);

		// If execlp fails
		perror("execlp failed");
		exit(EXIT_FAILURE);
	}
	else
	{ // Parent process
		// Wait for the child process to complete
		wait(&status);

		if (WIFEXITED(status))
		{
			printf("Child process exited with status %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("Child process did not exit successfully\n");
		}

		printf("Parent process (PID: %d) finished\n", getpid());
	}

	return 0;
}