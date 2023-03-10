#include <stdio.h>
#include <stdlib.h>
#include "./common.h"
#include "./common_threads.h"

volatile int	counter = 0;
int				loops;

void	*worker(void *arg)
{
	int	i;

	i = 0;
	while (i < loops)
	{
		counter++;
		i++;
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	pthread_t	p1;
	pthread_t	p2;
	
	if (argc != 2)
	{
		fprintf(stderr, "usage: threads <value>\n");
		exit(EXIT_FAILURE);
	}
	loops = atoi(argv[1]);
	printf("Initial value : %d\n", counter);

	pthread_create(&p1, NULL, worker, NULL);
	pthread_create(&p2, NULL, worker, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("Final value	: %d\n", counter);
	return (0);
}