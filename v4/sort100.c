#include "push_swap.h"

static void	ft_push_half(t_stacks *ptr_stacks)
{
	int	i;

	i = ptr_stacks->pos_a / 2;
	while (i > 0)
	{
		
	}
}

void	ft_sort_hundred(t_stacks *ptr_stacks)
{
	if (ptr_stacks->pos_a > 5)
		ft_push_half(ptr_stacks);
	if (ptr_stacks->pos_a > 5)
		ft_sort_hundred(ptr_stacks);
}
