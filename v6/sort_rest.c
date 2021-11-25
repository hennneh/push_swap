/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:50 by hlehmann          #+#    #+#             */
/*   Updated: 2021/11/25 16:38:53 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bck_srt_three(t_s *ps)
{
	if (ps->b[0] > ps->b[1] && ps->b[1] > ps->b[2] && ps->b[0] > ps->b[2])
		ft_thrtwoone(ps);
	else if (ps->b[0] < ps->b[1] && ps->b[1] > ps->b[2] && ps->b[0] < ps->b[2])
		ft_onethrtwo(ps);
	else if (ps->b[0] < ps->b[1] && ps->b[1] > ps->b[2] && ps->b[0] > ps->b[2])
		ft_twothrone(ps);
	else if (ps->b[0] > ps->b[1] && ps->b[1] < ps->b[2] && ps->b[0] < ps->b[2])
		ft_twoonethr(ps);
	else if (ps->b[0] > ps->b[1] && ps->b[1] < ps->b[2] && ps->b[0] > ps->b[2])
		ft_thronetwo(ps);
	else if (ps->b[0] < ps->b[1] && ps->b[1] < ps->b[2] && ps->b[0] < ps->b[2])
		ft_onetwothr(ps);
}

static void	ft_bck_srt(t_s *ps, int pshd)
{
	if (pshd == 1)
		pa(ps);
	else if (pshd == 2)
	{
		if (ps->b[0] > ps->b[1])
		{
			pa(ps);
			pa(ps);
		}
		else
		{
			sb(ps);
			pa(ps);
			pa(ps);
		}
	}
	else if (pshd == 3)
		ft_bck_srt_three(ps);
}

static void	ft_srt_bck(t_s *ps, int pshd)
{
	int	srt;

	srt = 0;
	if (pshd > 3)
	{
		srt = ft_psh_bck_hlf(ps, pshd);
		ft_sort_rest(ps, srt);
		ft_srt_bck(ps, (pshd - srt));
	}
	else
		ft_bck_srt(ps, pshd);
}

void	ft_sort_rest(t_s *ps, int srt)
{
	int	pshd;

	pshd = 0;
	if (srt > 3)
	{
		pshd = ft_psh_hlf(ps, srt);
		ft_sort_rest(ps, (srt - pshd));
	}	
	else
		ft_srt(ps, srt);
	if (pshd > 0)
		ft_srt_bck(ps, pshd);
}
