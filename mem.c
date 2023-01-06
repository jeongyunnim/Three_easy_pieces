#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./common.h"

int main(int argc, char *argv[])
{
	int	*p;
	int	i;

	p = malloc(sizeof(int) * 1);
	assert(p != NULL);
	*p = 0;
	i = 0;
	printf("(%d) address pointed to by p: %p\n", getpid(), p);
	while (i++ < 10)
	{
		Spin(1);
		*p = *p + 1;
		printf("(%d) p: %d\n", getpid(), *p);
	}
	free(p);
	return (0);
}