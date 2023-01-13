#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	char	*my_args[3];
	int 	rc;
	int		rc_wait;

	printf("hello world (pid:%d)\n", (int)getpid());
	rc = fork();
	if (rc < 0)
	{
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if (rc == 0)
	{
		// child: redirect standard output to a file
		close (STDOUT_FILENO);
		open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

		// exec "wc"
		my_args[0] = strdup("wc");// program: wc
		my_args[1] = strdup("p4.c");// arg: file to count
		my_args[2] = NULL;// mark end of array
		execvp(my_args[0], my_args);

	}
	else
	{
		// parent goes down this path (main)
		rc_wait = wait(NULL);
	}
	return (0);
}