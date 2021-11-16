#include "push_swap.h"

void	ft_label(t_s *ps)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = ps->hd + 1;
	while (i < ps->pa)
	{
		ps->e[i] = -1;
		i++;
	}
	tmp = ps->hd;
	while (i < ps->pa)
	{
		if (j == 0)
		{
			if (ps->a[j] > ps->a[tmp] && ps->a[j] > ps->a[ps->pa - 1])
			{
				ps->e[j] = 1;
				tmp = j;
			}
			else
				ps->e[j] = 0;
		}
		else if (j == ps->pa)
		{
			j = 0;
			i--;
		}
		if (ps->a[j] > ps->a[tmp] && ps->a[j] > ps->a[ps->hd])
		{
			ps->e[j] = 1;
			tmp = j;
		}
		else
			ps->e[j] = 0;
		i++;
	}
}

void	ft_inner(t_s *ps, int *i, int *j, int *tmp)
{
	while (*j != *i)
	{
		if (*j == 0)
		{
			if (ps->a[*j] > ps->a[*i] && ps->a[*j] > ps->a[*tmp])
			{
				ps->d[*i]++;
				*tmp = *j;
			}
		}
		else if (*j == ps->pa)
			*j = -1;
		else if (ps->a[*j] > ps->a[*i] && ps->a[*j] > ps->a[*tmp])
		{
			ps->d[*i]++;
			*tmp = *j;
		}
		*j = *j + 1;
	}
}

void	ft_find_head(t_s *ps)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < ps->pa)
	{
		j = i + 1;
		tmp = i;
		ft_inner(ps, &i, &j, &tmp);
		i++;
	}
	i = 1;
	ps->hd = 0;
	while (i < ps->pa)
	{
		if (ps->d[i] > ps->d[ps->hd])
			ps->hd = i;
		i++;
	}
}

void	ft_init_d(t_s *ps)
{
	int	i;

	i = 0;
	while (i < ps->pa)
	{
		ps->d[i] = 0;
		i++;
	}
}

void	ft_sort_rest(t_s *ps)
{
	ft_init_d(ps);
	ft_find_head(ps);
	ft_label(ps);
//	ft_sort_back(ps);
//	ft_rotate(ps);
}
