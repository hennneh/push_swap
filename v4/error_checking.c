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

int	ft_isint(int argc, char **argv)
{
	int	nbr;
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 12)
			return (1);
		nbr = ft_atol(argv[i]);
	}
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
		while (argv[i][j])
		{
			if (argv[i][j] < 58 && argv[i][j] > 47)
				j++;
			else
				return (1);
		}
		i++;
	}
	if (ft_isint(argc, argv))
		return (1)
	return (0);
}
