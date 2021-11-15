#include "push_swap.h"

void	sa(t_stacks *ptr_stacks)
{
	int	temp;

	if (ptr_stacks->pos_a > 1)
	{
		temp = ptr_stacks->stack_a[0];
		ptr_stacks->stack_a[0] = ptr_stacks->stack_a[1];
		ptr_stacks->stack_a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *ptr_stacks)
{
	int	temp;

	if (ptr_stacks->pos_b > 1)
	{
		temp = ptr_stacks->stack_b[0];
		ptr_stacks->stack_b[0] = ptr_stacks->stack_b[1];
		ptr_stacks->stack_b[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stacks *ptr_stacks)
{
	int	temp;

	if (ptr_stacks->pos_a > 1 && ptr_stacks->pos_b > 1)
	{
		temp = ptr_stacks->stack_b[0];
		ptr_stacks->stack_b[0] = ptr_stacks->stack_b[1];
		ptr_stacks->stack_b[1] = temp;
		temp = ptr_stacks->stack_a[0];
		ptr_stacks->stack_a[0] = ptr_stacks->stack_a[1];
		ptr_stacks->stack_a[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	pa(t_stacks *ptr_stacks)
{
	int	i;

	if (ptr_stacks->pos_b > 0)
	{
		i = ptr_stacks->pos_a;
		while (i > 0)
		{
			ptr_stacks->stack_a[i] = ptr_stacks->stack_a[i - 1];
			i--;
		}
		ptr_stacks->stack_a[0] = ptr_stacks->stack_b[0];
		if (ptr_stacks->pos_b > 1)
		{
			i = 0;
			while (i < (ptr_stacks->pos_b - 1))
			{
				ptr_stacks->stack_b[i] = ptr_stacks->stack_b[i + 1];
				i++;
			}
		}
		ptr_stacks->pos_a++;
		ptr_stacks->pos_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stacks *ptr_stacks)
{
	int	i;

	if (ptr_stacks->pos_a > 0)
	{
		i = ptr_stacks->pos_b;
		while (i > 0)
		{
			ptr_stacks->stack_b[i] = ptr_stacks->stack_b[i - 1];
			i--;
		}
		ptr_stacks->stack_b[0] = ptr_stacks->stack_a[0];
		if (ptr_stacks->pos_a > 1)
		{
			i = 0;
			while (i < (ptr_stacks->pos_a - 1))
			{
				ptr_stacks->stack_a[i] = ptr_stacks->stack_a[i + 1];
				i++;
			}
		}
		ptr_stacks->pos_a--;
		ptr_stacks->pos_b++;
		write(1, "pb\n", 3);
	}
}
