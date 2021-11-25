#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	r;
	int	i = 0;
	int limit = atoi(argv[1]);
	srand(time(NULL)); 
	while (i < limit)
	{
		r = rand();
		printf("%d ", r);
		i++;
	}
	printf("\n");
	return (0);
}
