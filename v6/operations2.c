/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlehmann <hlehmann@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:07:06 by hlehmann          #+#    #+#             */
/*   Updated: 2021/11/25 16:07:16 by hlehmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_s *ps)
{
	int	temp;
	int	i;

	i = 1;
	if (ps->pa > 1)
	{
		temp = ps->a[0];
		while (i < ps->pa)
		{
			ps->a[i - 1] = ps->a[i];
			i++;
		}
		ps->a[ps->pa - 1] = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_s *ps)
{
	int	temp;
	int	i;

	i = 1;
	if (ps->pb > 1)
	{
		temp = ps->b[0];
		while (i < ps->pb)
		{
			ps->b[i - 1] = ps->b[i];
			i++;
		}
		ps->b[ps->pb - 1] = temp;
		write(1, "rb\n", 3);
	}
}
