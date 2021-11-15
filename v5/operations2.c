#include "push_swap.h"

void	ra(t_s *ps)
{
	int	temp;
	int	i;

	i = 1;
	if (ps->pa > 1)
	{
		temp = ps->a[0];
		while (i < ps->pa)
		{
			ps->a[i - 1] = ps->a[i];
			i++;
		}
		ps->a[ps->pa - 1] = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_s *ps)
{
	int	temp;
	int	i;

	i = 1;
	if (ps->pb > 1)
	{
		temp = ps->b[0];
		while (i < ps->pb)
		{
			ps->b[i - 1] = ps->b[i];
			i++;
		}
		ps->b[ps->pb - 1] = temp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_s *ps)
{
	int	temp;
	int	i;

	i = 0;
	if (ps->pb > 1)
	{
		temp = ps->b[0];
		while (i < ps->pb)
		{
			ps->b[i - 1] = ps->b[i];
			i++;
		}
		ps->b[ps->pb - 1] = temp;
	}
	i = 0;
	if (ps->pa > 1)
	{
		temp = ps->a[0];
		while (i < ps->pa)
		{
			ps->a[i - 1] = ps->a[i];
			i++;
		}
		ps->a[ps->pa - 1] = temp;
	}
	write(1, "rr\n", 3);
}
