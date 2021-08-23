#include <stdio.h>
#include "push_swap.h"

static int	check_double(int *stack_a, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack_a[i] == stack_a[j])
				return (0)
			j++;
		}
		i++;
	}
	return (1);
}

static int	create_stack(int argc, char **argv, int *stack_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] >= '0' && argv[i][0] <= '9')
		{
			stack_a[j] = argv[i][0] - 48;
			i++;
			j++;
		}
		else
			return (0);
	}
	return (i - 1);
}

int	main(int argc, char **argv)
{
	int	len;
	int	stack_a[argc - 1];
	int	stack_b[argc - 1];

	if (!(len = create_stack(argc, argv, stack_a)))
		write(1, "Error\n", 6);
	return (0);
}
