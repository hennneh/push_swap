#include "push_swap.h"

static int	ft_find_head(t_stacks *ptr_stacks)
{
	int	i;
	int	head;
	int	*count;

	count = malloc(sizeof(int) * ptr_stacks->pos_a);
	head = 0;
	while (head < ptr_stacks->pos_a)
	{
		count[head] = 1;
		head++;
	}
	head = 0;
	while (head < ptr_stacks->pos_a)
	{
		i = head + 1;
		if (i == ptr_stacks->pos_a)
			i = 0;
		while (i != head)
		{
			if (i == 0)
			{
				if (ptr_stacks->stack_a[i] > ptr_stacks->stack_a[ptr_stacks->pos_a - 1] && ptr_stacks->stack_a[i] > ptr_stacks->stack_a[head])
					count[head]++;
			}
			else if (ptr_stacks->stack_a[i] > ptr_stacks->stack_a[i - 1] && ptr_stacks->stack_a[i] > ptr_stacks->stack_a[head])
				count[head]++;
			i++;
			if (i == ptr_stacks->pos_a)
				i = 0;
		}
		head++;
	}
	i = 1;
	head = 0;
	while (i < ptr_stacks->pos_a)
	{
		if (count[i] > count[head])
			head = i;
		else if (count[i] == count[head])
		{
			if (ptr_stacks->stack_a[i] < ptr_stacks->stack_a[head])
					head = i;
		}
		i++;
	}
	free(count);
	return (head);
}

void	ft_sort_hundred(t_stacks *ptr_stacks)
{
	int	i;

	i = ft_find_head(ptr_stacks);
}
