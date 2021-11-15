#include "push_swap.h"

void	sa(t_s *ps)
{
	int	temp;

	if (ps->pa > 1)
	{
		temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_s *ps)
{
	int	temp;

	if (ps->pb > 1)
	{
		temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_s *ps)
{
	int	temp;

	if (ps->pa > 1 && ps->pb > 1)
	{
		temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = temp;
		temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = temp;
		write(1, "ss\n", 3);
	}
}

void	pa(t_s *ps)
{
	int	i;

	if (ps->pb > 0)
	{
		i = ps->pa;
		while (i > 0)
		{
			ps->a[i] = ps->a[i - 1];
			i--;
		}
		ps->a[0] = ps->b[0];
		if (ps->pb > 1)
		{
			i = 0;
			while (i < (ps->pb - 1))
			{
				ps->b[i] = ps->b[i + 1];
				i++;
			}
		}
		ps->pa++;
		ps->pb--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_s *ps)
{
	int	i;

	if (ps->pa > 0)
	{
		i = ps->pb;
		while (i > 0)
		{
			ps->b[i] = ps->b[i - 1];
			i--;
		}
		ps->b[0] = ps->a[0];
		if (ps->pa > 1)
		{
			i = 0;
			while (i < (ps->pa - 1))
			{
				ps->a[i] = ps->a[i + 1];
				i++;
			}
		}
		ps->pa--;
		ps->pb++;
		write(1, "pb\n", 3);
	}
}
