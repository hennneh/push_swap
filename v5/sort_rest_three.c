#include "push_swap.h"

void	ft_sort_back(t_s *ps)
{
	int	pos;
	int	i;

	pos = -1;
	i = 1;
	while (ps->pb > 0)
	{
		while (i < ps->pa)
		{
			if (ps->a[i] > ps->b[0] && ps->a[i - 1] < ps->b[0])
				pos = i;
			i++;
		}
		if (pos == -1)
			pos = 0;
		while (pos > 0)
		{
			ra(ps);
			pos--;
		}
		pa(ps);
		i = 1;
		pos = -1;
	}
}

//everything that follows is old and sucks!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
int	ft_find_big(t_s *ps)
{
	int	n;
	int	pos;
	int	j;

	pos = 0;
	n = 1;
	j = 0;
	while (ps->b[0] != ps->a[pos] + n)
	{
		pos++;
		j++;
		if (j == ps->pa)
		{
			j = 0;
			pos = 0;
			n++;
		}
	}
	return (pos);
}

int	ft_find_pos(t_s *ps)
{
	int	pos;
	int	i;
	int	size;

	i = 0;
	while (i < ps->pa)
	{
		if (
	}
	return (pos);
}

void	ft_sort_back(t_s *ps)
{
	int	pos;

	while (ps->pb > 0)
	{
		pos = ft_find_pos(ps);
		while (pos > 0)
		{
			ra(ps);
			pos--;
		}
		pa(ps);
	}
}
*/
