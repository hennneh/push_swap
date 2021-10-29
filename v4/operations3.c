#include "push_swap.h"

void	rra(t_stacks *ptr_stacks)
{
	int	temp;
	int	i;

	if (ptr_stacks->pos_a > 1)
	{
		temp = ptr_stacks->stack_a[ptr_stacks->pos_a - 1];
		i = ptr_stacks->pos_a - 1;
		while (i > 0)
		{
			ptr_stacks->stack_a[i] = ptr_stacks->stack_a[i - 1];
			i--;
		}
		ptr_stacks->stack_a[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stacks *ptr_stacks)
{
	int	temp;
	int	i;

	if (ptr_stacks->pos_b > 1)
	{
		temp = ptr_stacks->stack_b[ptr_stacks->pos_b - 1];
		i = ptr_stacks->pos_b - 1;
		while (i > 0)
		{
			ptr_stacks->stack_b[i] = ptr_stacks->stack_b[i - 1];
			i--;
		}
		ptr_stacks->stack_b[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stacks *ptr_stacks)
{
	int	temp;
	int	i;

	if (ptr_stacks->pos_a > 1)
	{
		temp = ptr_stacks->stack_a[ptr_stacks->pos_a - 1];
		i = ptr_stacks->pos_a - 1;
		while (i > 0)
		{
			ptr_stacks->stack_a[i] = ptr_stacks->stack_a[i - 1];
			i--;
		}
		ptr_stacks->stack_a[0] = temp;
	}
	if (ptr_stacks->pos_b > 1)
	{
		temp = ptr_stacks->stack_b[ptr_stacks->pos_b - 1];
		i = ptr_stacks->pos_b - 1;
		while (i > 0)
		{
			ptr_stacks->stack_b[i] = ptr_stacks->stack_b[i - 1];
			i--;
		}
		ptr_stacks->stack_b[0] = temp;
	}
	write(1, "rrr\n", 4);
}
