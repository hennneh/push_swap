#include "push_swap.h"

static void	ft_sort_five_three_a(t_s *ps)
{
	if (ps->a[0] == 4 && ps->a[1] == 3)
	{
		ra(ps);
		sa(ps);
	}
	else if (ps->a[0] == 2 && ps->a[1] == 4)
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->a[0] == 3 && ps->a[1] == 4)
		rra(ps);
	else if (ps->a[0] == 3 && ps->a[1] == 2)
		sa(ps);
	else if (ps->a[0] == 4 && ps->a[1] == 2)
		ra(ps);
}

void		ft_sort_five(t_s *ps)
{
	while (ps->pa > 3)
	{
		if (ps->a[0] == 0 || ps->a[0] == 1)
		{
			pb(ps);
			if (ps->pa == 3)
				break ;
		}
		ra(ps);
	}
	if (ps->b[0] == 0)
		rb(ps);
	ft_sort_five_three_a(ps);
	pa(ps);
	pa(ps);
}
