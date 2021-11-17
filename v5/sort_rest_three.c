#include "push_swap.h"

void	ft_sort_back(t_s *ps)
{
	while (ps->pb > 0)
	{
		while (ps->a[0] != ps->b[0] + 1)
			ra(ps);
		pa(ps);
	}
}

void	ft_rotate(t_s *ps)
{
	while (ps->a[0] != 0)
		ra(ps);
}
