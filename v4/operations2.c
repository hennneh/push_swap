#include "push_swap.h"

void	ra(t_stacks *ptr_stacks)
{
	int	temp;
	int	i;

	i = 1;
	if (ptr_stacks->pos_a > 1)
	{
		temp = ptr_stacks->stack_a[0];
		while (i < ptr_stacks->pos_a)
		{
			ptr_stacks->stack_a[i - 1] = ptr_stacks->stack_a[i];
			i++;
		}
		ptr_stacks->stack_a[ptr_stacks->pos_a - 1] = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stacks *ptr_stacks)
{
	int	temp;
	int	i;

	i = 1;
	if (ptr_stacks->pos_b > 1)
	{
		temp = ptr_stacks->stack_b[0];
		while (i < ptr_stacks->pos_b)
		{
			ptr_stacks->stack_b[i - 1] = ptr_stacks->stack_b[i];
			i++;
		}
		ptr_stacks->stack_b[ptr_stacks->pos_b - 1] = temp;
		write(1, "rb\n", 3);
	}
}
