/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:41 by hlehmann          #+#    #+#             */
/*   Updated: 2021/11/25 16:40:49 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_onetwothr(t_s *ps)
{
	rb(ps);
	sb(ps);
	pa(ps);
	pa(ps);
	rrb(ps);
	pa(ps);
}

static void	ft_srt_two(t_s *ps)
{
	if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2]
		&& ps->a[0] > ps->a[2])
	{
		ra(ps);
		sa(ps);
		rra(ps);
		sa(ps);
	}
	else if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2]
		&& ps->a[0] < ps->a[2])
	{
		ra(ps);
		sa(ps);
		rra(ps);
	}
	else if (ps->a[0] > ps->a[1] && ps->a[1] > ps->a[2]
		&& ps->a[0] > ps->a[2])
	{
		sa(ps);
		ra(ps);
		sa(ps);
		rra(ps);
		sa(ps);
	}
}

void	ft_srt(t_s *ps, int srt)
{
	if (srt == 2 && ps->a[0] > ps->a[1])
		sa(ps);
	else if (srt == 3)
	{
		if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[0] < ps->a[2])
			sa(ps);
		else if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2]
			&& ps->a[0] > ps->a[2])
		{
			sa(ps);
			ra(ps);
			sa(ps);
			rra(ps);
		}
		else
			ft_srt_two(ps);
	}
}
