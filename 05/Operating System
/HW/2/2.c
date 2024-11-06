#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t child_pid = fork();

	if (child_pid > 0)
	{
		// Parent process
		sleep(60);
	}
	else if (child_pid == 0)
	{
		// Child process
		exit(0);
	}

	return 0;
}