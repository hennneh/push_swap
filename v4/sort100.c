#include "push_swap.h"

static void	ft_move_b(t_stacks *ptr_stacks)
{
	int	i;

	i = 1;
	while (i < ptr_stacks->pos_a)
	{
		if (ptr_stacks->stack_a[i] < ptr_stacks->stack_a[i - 1])
		{
			ra(ptr_stacks);
			pb(ptr_stacks);
		}
	}
}

void	ft_sort_hundred(t_stacks *ptr_stacks)
{
	ft_move_b(ptr_stacks);
}
