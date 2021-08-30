#include <stdio.h>
#include "push_swap.h"

int	is_digit(int argc, char **argv)
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
	return (0);
}

int	checks(int argc, char **argv, int *stack_a, int *stack_c)
{
	int	valid;

	valid = is_digit(argc, argv);
	if (valid < 0)
		return (-1);

}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_c;

	stack_a = malloc(sizeof(int) * (argc - 1));
	stack_b = malloc(sizeof(int) * (argc - 1));
	stack_c = malloc(sizeof(int) * (argc - 1));
	checks(argc, argv, stack_a, stack_c);
	return (0);
}
