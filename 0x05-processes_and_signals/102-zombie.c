#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * infinite_while - an function that offers an infinite while loop
 * Return: 0 if successful
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - the entry point of the program
 * Return: EXIT_SUCCESS on success
 */

int main(void)
{
	int i = 0;
	pid_t z_process;

	while (i < 5)
	{
		z_process = fork();

		if (z_process != 0)
		{
			printf("Zombie process created, PID: %u\n", z_process);
			sleep(1);
			i++;
		}
		else
			exit(0);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
