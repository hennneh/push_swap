#include "push_swap.h"

int	ft_issorted(t_stacks *ptr_stacks)
{
	int	i;

	i = 1;
	if (ptr_stacks->pos_b == 0)
	{
		while (i < ptr_stacks->pos_a)
		{
			if (ptr_stacks->stack_a[i - 1] > ptr_stacks->stack_a[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_sort_rest(t_stacks *ptr_stacks)
{
	int	i;
	
	i = 0;
	while (1 <= ptr_stacks->pos_a)
	{
		while (ptr_stacks->stack_a[0] != i)
			ra(ptr_stacks);
		pb(ptr_stacks);
		i++;
	}
	i = ptr_stacks->pos_b - 1;
	while (i >= 0)
	{
		pa(ptr_stacks);
		i--;
	}
}

void	ft_sort_three(t_stacks *ptr_stacks)
{
	if (ptr_stacks->stack_a[0] == 2 && ptr_stacks->stack_a[1] == 1)
	{
		ra(ptr_stacks);
		ra(ptr_stacks);
	}
	else if (ptr_stacks->stack_a[0] == 0 && ptr_stacks->stack_a[1] == 2)
	{
		rra(ptr_stacks);
		sa(ptr_stacks);
	}
	else if (ptr_stacks->stack_a[0] == 1 && ptr_stacks->stack_a[1] == 2)
		rra(ptr_stacks);
	else if (ptr_stacks->stack_a[0] == 1 && ptr_stacks->stack_a[1] == 0)
		sa(ptr_stacks);
	else if (ptr_stacks->stack_a[0] == 2 && ptr_stacks->stack_a[1] == 0)
		ra(ptr_stacks);
}

void	ft_sort(t_stacks *ptr_stacks)
{
	if (ft_issorted(ptr_stacks))
		return ;
	if (ptr_stacks->pos_a == 3)
		ft_sort_three(ptr_stacks);
/*	else if (ptr_stacks->pos_a == 5)							//not implemented
		ft_sort_five(ptr_stacks);								//not implemented
	else if (ptr_stacks->pos_a == 100)							//not implemented
		ft_sort_hundred(ptr_stacks);							//not implemented
	else if (ptr_stacks->pos_a == 500)							//not implemented
		ft_sort_fivehundred(ptr_stacks);*/						//not implemented
	else
		ft_sort_rest(ptr_stacks);
}
