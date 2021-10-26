#include "push_swap.h"

void	ft_free(t_stacks *ptr_stacks)
{
	free(ptr_stacks->stack_a);
	free(ptr_stacks->stack_b);
	free(ptr_stacks->stack_c);
}

int	ft_error(t_stacks *ptr_stacks)
{
	write(2, "Error\n", 6);
	ft_free(ptr_stacks);
	return (1);
}

int	ft_isnum(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] && argv[i][j] > 47 && argv[i][j] < 58)
			j++;
		if (argv[i][j - 1] > 57 || argv[i][j - 1] < 48)
			return (1);
		i++;
	}
	return (0);
}
