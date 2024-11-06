#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
	int i, pid;
	for (i = 0; i <= 2; i++)
	{
		fork();
		printf("%d\n", getpid());
		pid = wait(NULL);
		printf("%d\n", pid);
	}

	return 0;
}
