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
