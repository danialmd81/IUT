#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void* thread_function(void* arg)
{
	printf("Thread created\n");
	return NULL;
}

int main()
{
	pthread_t thread;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		fork();
		if (pthread_create(&thread, NULL, thread_function, NULL) != 0)
		{
			perror("pthread_create failed");
			exit(EXIT_FAILURE);
		}
	}

	fork();
	printf("Process ID: %d\n", getpid());

	return 0;
}