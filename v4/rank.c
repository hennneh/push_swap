#include "push_swap.h"

void	ft_rank(int argc, char **argv, t_stacks *ptr_stacks)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ptr_stacks->stack_c[i - 1] = ft_atoi(argv[i]);
		i++;
	}
}
