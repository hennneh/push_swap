#include "push_swap.h"

void	ft_move(t_stacks *ptr_stacks)
{
	int	i;

	i = 0;
	while (i < ptr_stacks->pos_a)
	{
		if (ptr_stacks->d[ptr_stacks->stack_a[0]] == 0)
			pb(ptr_stacks);
		else
			ra(ptr_stacks);
		i++;
	}
}

int	ft_find_pos(t_stacks *ptr_stacks)
{
	int	pos;

	pos = 0;
	while (ptr_stacks->stack_a[pos] != ptr_stacks->stack_b[0] - 1)
		pos++;
	return (pos + 1);
}

void	ft_back(t_stacks *ptr_stacks)
{
	int	pos;

	while (ptr_stacks->pos_b != 0)
	{
		pos = ft_find_pos(ptr_stacks);
		if (ptr_stacks->pos_a / 2 > pos)
		{
			while (pos > 0)
			{
				ra(ptr_stacks);
				pos--;
			}
		}
		else
		{
			pos = ptr_stacks->pos_a - pos;
			while (pos > 0)
			{
				rra(ptr_stacks);
				pos--;
			}
		}
		pa(ptr_stacks);
	}
}

void	ft_top(t_stacks *ptr_stacks)
{
	int	pos;

	pos = 0;
	while (ptr_stacks->stack_a[pos] != 0)
		pos++;
	if (ptr_stacks->pos_a / 2 > pos)
	{
		while (pos > 0)
		{
			ra(ptr_stacks);
			pos--;
		}
	}
	else
	{
		pos = ptr_stacks->pos_a - pos;
		while (pos > 0)
		{
			rra(ptr_stacks);
			pos--;
		}
	}
}

void	ft_cnt(int *cnt, t_stacks *ptr_stacks, int head)
{
	while (head < ptr_stacks->pos_a)
	{
		cnt[head] = 1;
		head++;
	}
}
