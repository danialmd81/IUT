#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void* runner(void* args)
{
	for (int i = 0; i < 20; i++)
		printf("runner %d at process %d : %d\n", *(int*)args, getpid(), i);
}

// test getpid and fork return value

int main(int argc, char** argv)
{
	printf("--beginning of program\n");

	pthread_t t1, t2;
	pthread_attr_t thread_attr;
	int t1_id = 1, t2_id = 2;
	pthread_attr_init(&thread_attr);
	pthread_create(&t1, &thread_attr, runner, (void*)&t1_id);
	pthread_create(&t2, &thread_attr, runner, (void*)&t2_id);

	int counter = 0, status;
	pid_t pid = fork();

	if (pid == 0) // child process
	{

		// pthread_create(&t1, &thread_attr, runner,(void*)&t1_id);
		// pthread_create(&t2, &thread_attr, runner,(void*)&t2_id);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
		printf("child process with pid %d finihsed.\n", getpid());
	}
	else if (pid > 0) // parent process
	{
		pthread_join(t1, NULL);
		// printf("Parent: after t1 join\n ");
		pthread_join(t2, NULL);
		wait(&status);
		printf("End of parent\n ");
	}
	else
	{
		// fork failed
		printf("fork() failed!\n");
		return 1;
	}

	printf("--end of program--\n");

	return 0;
}
