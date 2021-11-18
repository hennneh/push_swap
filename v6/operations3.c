#include "push_swap.h"

void	rra(t_s *ps)
{
	int	temp;
	int	i;

	if (ps->pa > 1)
	{
		temp = ps->a[ps->pa - 1];
		i = ps->pa - 1;
		while (i > 0)
		{
			ps->a[i] = ps->a[i - 1];
			i--;
		}
		ps->a[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_s *ps)
{
	int	temp;
	int	i;

	if (ps->pb > 1)
	{
		temp = ps->b[ps->pb - 1];
		i = ps->pb - 1;
		while (i > 0)
		{
			ps->b[i] = ps->b[i - 1];
			i--;
		}
		ps->b[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_s *ps)
{
	int	temp;
	int	i;

	if (ps->pa > 1)
	{
		temp = ps->a[ps->pa - 1];
		i = ps->pa - 1;
		while (i > 0)
		{
			ps->a[i] = ps->a[i - 1];
			i--;
		}
		ps->a[0] = temp;
	}
	if (ps->pb > 1)
	{
		temp = ps->b[ps->pb - 1];
		i = ps->pb - 1;
		while (i > 0)
		{
			ps->b[i] = ps->b[i - 1];
			i--;
		}
		ps->b[0] = temp;
	}
	write(1, "rrr\n", 4);
}
