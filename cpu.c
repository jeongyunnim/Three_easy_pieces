#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "./common.h"

int main(int argc, char *argv[])
{
    char	*str;
	int		i;
	
	if (argc!=2)
	{
		fprintf(stderr, "usage: cpu <string>\n");
		exit(1);
    }
	i = 0;
	str = argv[1];
    while (i++ < 10)
	{
		Spin(1);
        printf("%s\n", str);
    }
	return 0;
}