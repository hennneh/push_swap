/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:08:34 by hlehmann          #+#    #+#             */
/*   Updated: 2021/11/25 16:08:36 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_thrtwoone(t_s *ps)
{
	pa(ps);
	pa(ps);
	pa(ps);
}

void	ft_onethrtwo(t_s *ps)
{
	sb(ps);
	pa(ps);
	sb(ps);
	pa(ps);
	pa(ps);
}

void	ft_twothrone(t_s *ps)
{
	sb(ps);
	pa(ps);
	pa(ps);
	pa(ps);
}

void	ft_twoonethr(t_s *ps)
{
	rb(ps);
	sb(ps);
	pa(ps);
	rrb(ps);
	pa(ps);
	pa(ps);
}

void	ft_thronetwo(t_s *ps)
{
	pa(ps);
	sb(ps);
	pa(ps);
	pa(ps);
}
