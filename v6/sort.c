/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:04 by hlehmann          #+#    #+#             */
/*   Updated: 2021/11/25 16:09:28 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * checking if stack a is sorted
 */

int	ft_issorted(t_s *ps)
{
	int	i;

	i = 1;
	if (ps->pb == 0)
	{
		while (i < ps->pa)
		{
			if (ps->a[i - 1] > ps->a[i])
				return (0);
			i++;
		}
	}
	return (1);
}

/*
 * hard coded solutions for all possible inputs
 * with 3 numbers
 */

void	ft_sort_three(t_s *ps)
{
	if (ps->a[0] == 2 && ps->a[1] == 1)
	{
		ra(ps);
		sa(ps);
	}
	else if (ps->a[0] == 0 && ps->a[1] == 2)
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->a[0] == 1 && ps->a[1] == 2)
		rra(ps);
	else if (ps->a[0] == 1 && ps->a[1] == 0)
		sa(ps);
	else if (ps->a[0] == 2 && ps->a[1] == 0)
		ra(ps);
}

/*
 * checking if the input is sorted already and then
 * checking the amount of input and determining 
 * which sorting algorithm to use:
 * sort3, sort5, or sort_rest
 */

void	ft_sort(t_s *ps)
{
	if (ft_issorted(ps))
		return ;
	if (ps->pa == 3)
		ft_sort_three(ps);
	else if (ps->pa == 5)
		ft_sort_five(ps);
	else
		ft_sort_rest(ps, ps->pa);
}
