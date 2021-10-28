#include "push_swap.h"

void	ft_rank(int argc, char **argv, t_stacks *ptr_stacks)
{
	int	i;
	int	temp;

	i = 1;
	while (i < argc)
	{
		ptr_stacks->stack_c[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 1;
	while (i < (argc - 1))
	{
		if (ptr_stacks->stack_c[i - 1] > ptr_stacks->stack_c[i])
		{
			temp = ptr_stacks->stack_c[i];
			ptr_stacks->stack_c[i] = ptr_stacks->stack_c[i - 1];
			ptr_stacks->stack_c[i - 1] = temp;
			i = 0;
		}
		i++;
	}
}
