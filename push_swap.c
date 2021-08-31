#include <stdio.h>
#include "push_swap.h"

int	check_dup(int argc, int *stack_c)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		if (stack_c[i] == stack_c[j])
			return (-1);
		i++;
	}
	return (0);
}

int	pre_sort(int *stack_a, int *stack_c, int argc)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (stack_c[i] < stack_c[j] && j < (argc - 1))
			j++;
		if (stack_c[i] > stack_c[j])
		{
			temp = stack_c[j];
			stack_c[j] = stack_c[i];
			stack_c[i] = temp;
			i = 0;
		}
		else
			i++;
	}
	temp = check_dup(argc, stack_c);
	if (temp == -1)
		return (-1);
}

void	fill_stack(int argc, char **argv, int *stack_a, int *stack_c)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		stack_c[j] = atoi(argv[i]);
		i++;
		j++;
	}
}

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
	fill_stack(argc, argv, stack_a, stack_c);
	pre_sort(stack_a, stack_c, argc);
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
