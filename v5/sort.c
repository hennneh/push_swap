#include "push_swap.h"

int		ft_issorted(t_s *ps)
{
	int	i;

	i = 1;
	if (ps->pb == 0)
	{
		while (i < ps->pa)
		{
			if (ps->a[i - 1] > ps->a[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_sort_three(t_s *ps)
{
	if (ps->a[0] == 2 && ps->a[1] == 1)
	{
		ra(ps);
		sa(ps);
	}
	else if (ps->a[0] == 0 && ps->a[1] == 2)
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->a[0] == 1 && ps->a[1] == 2)
		rra(ps);
	else if (ps->a[0] == 1 && ps->a[1] == 0)
		sa(ps);
	else if (ps->a[0] == 2 && ps->a[1] == 0)
		ra(ps);
}

void	ft_sort(t_s *ps)
{
	if (ft_issorted(ps))
		return ;
	if (ps->pa == 3)
		ft_sort_three(ps);
	else if (ps->pa == 5)
		ft_sort_five(ps);
/*	else
		ft_sort_rest(ps); */
}
