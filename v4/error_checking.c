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

static int	ft_isint(int argc, char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (1);
		if (ft_strlen(argv[i]) == 11 && argv[i][0] != '-')
			return (1);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		return (0);
	}
	return (0);
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
		return (1);
	return (0);
}
