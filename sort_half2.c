/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_half2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:01:31 by hlehmann          #+#    #+#             */
/*   Updated: 2021/11/25 18:01:33 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mmma(t_s *ps, int srt)
{
	int	i;

	i = 0;
	ps->mn = ps->a[0];
	ps->mx = ps->a[0];
	while (i < srt)
	{
		if (ps->a[i] > ps->mx)
			ps->mx = ps->a[i];
		if (ps->a[i] < ps->mn)
			ps->mn = ps->a[i];
		i++;
	}
	ps->md = (ps->mx - ps->mn) / 2 + ps->mn;
}

int	ft_srtmmma(t_s *ps, int srt, int *pshd)
{
	int	i;
	int	rt;

	rt = 0;
	i = 0;
	while (i < srt && *pshd <= ((ps->mx - ps->mn) / 2))
	{
		if (ps->a[0] <= ps->md)
		{
			pb(ps);
			*pshd = *pshd + 1;
		}
		else
		{
			ra(ps);
			rt++;
		}
		i++;
	}
	return (rt);
}

int	ft_psh_hlf(t_s *ps, int srt)
{
	int	rt;
	int	pshd;
	int	i;

	pshd = 0;
	i = 0;
	ft_mmma(ps, srt);
	rt = ft_srtmmma(ps, srt, &pshd);
	while (i < rt)
	{
		rra(ps);
		i++;
	}
	return (pshd);
}
