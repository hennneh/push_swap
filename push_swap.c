#include <stdio.h>
#include "push_swap.h"

static int	create_stack(int argc, char **argv, int *stack_a)
{
	
}

int	main(int argc, char **argv)
{
	int	*stack_a;

	stack_a = malloc(sizeof(int) * (argc - 1));
	create_stack(argc, argv, stack_a);
	return (0);
}
