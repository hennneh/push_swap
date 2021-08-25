#include <stdio.h>
#include "push_swap.h"

int	check_input(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] <= '9' && argv[i][j] >= '0')
				j++;
			else
				return (-1);
		}
		i++;
	}
}

static int	create_stack(int argc, char **argv, int *stack_a)
{
	int	*sort;
	int	i;
	int	j;

	i = 0;
	sort = malloc(sizeof(int) * (argc - 1));
	while (i < argc - 1)
	{
		j = ft_atoi(argv[i + 1];
		sort[i] = ft_atoi(argv[i + 1];
		
	}
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = malloc(sizeof(int) * (argc - 1));
	stack_b = malloc(sizeof(int) * (argc - 1));
	create_stack(argc, argv, stack_a);
	return (0);
}
