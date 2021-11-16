#include "push_swap.h"

/*
 * hard coded solution for sort 3
 * after two smallest ints have 
 * been pushed to stack b already
 */

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

/*
 * algorithm to sort 5 inputs
 * first pushing the two smallest ints
 * onto stack b, then sorting stack a
 * with sub-function and finally
 * pushing back from stack b to a
 */

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
