#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int gloabal_var = 10;

int main(int argc, char const* argv[])
{
	int local_var = 20;

	pid_t pid = fork();

	if (pid == 0)
	{
		// Child process
		gloabal_var += 10;
		local_var += 10;
		printf("Child: global_var = %d, local_var = %d\n", gloabal_var, local_var);
	}
	else if (pid > 0)
	{
		// Parent process
		sleep(10);
		printf("Parent: global_var = %d, local_var = %d\n", gloabal_var, local_var);
	}
	else
	{
		/* code */
	}

	return 0;
}
