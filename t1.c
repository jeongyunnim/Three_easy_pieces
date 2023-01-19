#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include "common.h"
#include "common_threads.h"

static volatile int counter = 0;

/*
mythread()
simply adds 1 to counter repeatedly, in a loop No, 
this is not how you would add 10,000,000 to a counter,
but it shows the problem nicely.
*/

void	*mythread(void *arg)
{
	int	i;

	printf("%s: begin\n", (char *)arg);
	i = 0;
	while (i++ < 10000000)
	{
		counter = counter + 1;
	}
	printf("%s: done\n", (char *)arg);
	return (NULL);
}

/*
	main()
	Just launches two threads (pthread_create)
	and then waits for them (pthread_join)
*/

int main(int argc, char *arg[])
{
	pthread_t	p1;
	pthread_t	p2;

	printf("main: begin (counter: %d)\n", counter);
	pthread_create(&p1, NULL, mythread, "A");
	pthread_create(&p2, NULL, mythread, "B");
	// join waits for the threads to finish
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("main: end (counter: %d)\n", counter);
	return (0);
}
