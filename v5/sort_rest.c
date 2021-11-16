#include "push_swap.h"

/*
 * logic for if statement that
 * needs to be separated because
 * of norm issues for the function
 * length; it simply checks if the
 * int should be pushed or not
 */

void	ft_if(t_s *ps, int *j, int *tmp)
{
	if (ps->a[*j] > ps->a[*tmp] && ps->a[*j] > ps->a[ps->pa - 1])
	{
		ps->e[ps->a[*j]] = 1;
		*tmp = *j;
	}
	else
		ps->e[ps->a[*j]] = 0;
}

/*
 * logig for else statment, 
 * because the of line issues
 * according to the norm; it simply
 * checks if the int should be pushed
 * to b or not and indexes it accordingly
 */

void	ft_else(t_s *ps, int *j, int *tmp)
{
	if (ps->a[*j] > ps->a[*tmp] && ps->a[*j] > ps->a[ps->hd])
	{
		ps->e[ps->a[*j]] = 1;
		*tmp = *j;
	}
	else
		ps->e[ps->a[*j]] = 0;
}

/*
 * labeling each element of stack a
 * with 1 (keep this number) or 
 * 0 (push to b) according to the head
 * we found earlier
 * the labels are saved in stack e
 * in accordance to the value, not the
 * position, in stack a
 */

void	ft_label(t_s *ps, int i, int j, int tmp)
{
	while (i < ps->pa)
	{
		if (j == 0)
			ft_if(ps, &j, &tmp);
		else if (j == ps->pa)
		{
			j = -1;
			i--;
		}
		else
			ft_else(ps, &j, &tmp);
		i++;
		j++;
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
	//test askjdfölaskdfjölaskjdfölaskjdfölaskjdfölkasjdfölkajsdöflkjasödlfkjasöldkfjöasldkjfölaskdjf
	int	i = 0;
	while (i < ps->pa)
	{
		printf("#%d: %d\n", i, ps->e[i]);
		i++;
	}
	//end of test laöskdfjölaskdjflökajsdfölkjasdöfljksdölaksdjföalsdkfjöalsdkjfölaskjdflösakdfjsaöldfkj
//	ft_sort_back(ps);
//	ft_rotate(ps);
}
