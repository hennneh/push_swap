#include "push_swap.h"

void	ft_move_labeled(t_s *ps)
{
	int	i;
	int	j;

	j = ps->pa;
	i = 0;
	while (i < j)
	{
		if (ps->e[ps->a[0]] == 0)
			pb(ps);
		else
			ra(ps);
		i++;
	}
}

/*
 * the inner loop to finding the head
 * because norm doesn't allow more
 * lines of code per function
 */

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

/*
 * checking for each number, how many ints
 * afterwards are already in the right order
 * and then returning the position of the head
 * with the most pre-sorted ints
 */

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

/*
 * initializing stack d
 */

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

/*
 * caller function that only calls the other functions
 * first d is initialized, then we find the head
 * for the biggest amount of already sorted ints, 
 * label all the ints on stack a according to the 
 * head we found and push them to b, then sorting back 
 * into the right positions of a and finally rotating
 * a until the smallest int is at the top
 */

void	ft_sort_rest(t_s *ps)
{
	ft_init_d(ps);
	ft_find_head(ps);
	ft_label(ps, 1, (ps->hd + 1), ps->hd);
	ps->e[ps->a[ps->hd]] = 1;
	ft_move_labeled(ps);
//	ft_sort_back(ps);
//	ft_rotate(ps);
}
