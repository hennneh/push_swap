#include "push_swap.h"

static int	ft_find_head(t_stacks *ptr_stacks)
{
	int	i;
	int	head;
	int	*count;

	count = malloc(sizeof(int) * ptr_stacks->pos_a);
	head = 0;
	i = 1;
	while (head < ptr_stacks->pos_a)
	{
		count[head] = 1;
		head++;
	}
	head = 0;
	while (i != ptr_stacks->stack_a[head])
	{
		if (ptr_stacks->stack_a[i] > ptr_stacks->stack_a[head])
			count[head]++;
		i++;
		if (i == ptr_stacks->pos_a)
			i = 0;
	}
}

void	ft_sort_hundred(t_stacks *ptr_stacks)
{
	int	i;

	i = ft_find_head(ptr_stacks);
}
