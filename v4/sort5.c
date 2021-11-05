#include "push_swap.h"

static void	ft_sort_five_three_a(t_stacks *ptr_stacks)
{
	if (ptr_stacks->stack_a[0] == 4 && ptr_stacks->stack_a[1] == 3)
	{
		ra(ptr_stacks);
		ra(ptr_stacks);
	}
	else if (ptr_stacks->stack_a[0] == 2 && ptr_stacks->stack_a[1] == 4)
	{
		rra(ptr_stacks);
		sa(ptr_stacks);
	}
	else if (ptr_stacks->stack_a[0] == 3 && ptr_stacks->stack_a[1] == 4)
		rra(ptr_stacks);
	else if (ptr_stacks->stack_a[0] == 3 && ptr_stacks->stack_a[1] == 2)
		sa(ptr_stacks);
	else if (ptr_stacks->stack_a[0] == 4 && ptr_stacks->stack_a[1] == 2)
		ra(ptr_stacks);
}

void	ft_sort_five(t_stacks *ptr_stacks)
{
	while (ptr_stacks->pos_a > 3)
	{
		if (ptr_stacks->stack_a[0] == 0 || ptr_stacks->stack_a[0] == 1)
		{
			pb(ptr_stacks);
			if (ptr_stacks->pos_a == 3)
				break ;
		}
		ra(ptr_stacks);
	}
	if (ptr_stacks->stack_b[0] == 0)
		rb(ptr_stacks);
	ft_sort_five_three_a(ptr_stacks);
	pa(ptr_stacks);
	pa(ptr_stacks);
}
