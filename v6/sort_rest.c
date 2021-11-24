#include "push_swap.h"

static int	ft_psh_hlf(t_s *ps, int srt)
{
	int	rt;
	int	min;
	int	max;
	int	i;
	int	pshd;
	int	mid;

	rt = 0;
	pshd = 0;
	i = 0;
	min = ps->a[0];
	max = ps->a[0];
	while (i < srt)
	{
		if (ps->a[i] > max)
			max = ps->a[i];
		if (ps->a[i] < min)
			min = ps->a[i];
		i++;
	}
	mid = (max - min) / 2 + min;
	i = 0;
	while (i < srt && pshd <= ((max - min) / 2))
	{
		if (ps->a[0] <= mid)
		{
			pb(ps);
			pshd++;
		}
		else
		{
			ra(ps);
			rt++;
		}
		i++;
	}
	i = 0;
	while (i < rt)
	{
		rra(ps);
		i++;
	}
	return (pshd);
}

static void	ft_srt(t_s *ps, int srt)
{
	if (srt == 2 && ps->a[0] > ps->a[1])
		sa(ps);
	else if (srt == 3)
	{
		if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[0] < ps->a[2])
			sa(ps);
		else if (ps->a[0] > ps->a[1] && ps->a[1] < ps->a[2] && ps->a[0] > ps->a[2])
		{
			sa(ps);
			ra(ps);
			sa(ps);
			rra(ps);
		}
		else if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
		{
			ra(ps);
			sa(ps);
			rra(ps);
			sa(ps);
		}
		else if (ps->a[0] < ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] < ps->a[2])
		{
			ra(ps);
			sa(ps);
			rra(ps);
		}
		else if (ps->a[0] > ps->a[1] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
		{
			sa(ps);
			ra(ps);
			sa(ps);
			rra(ps);
			sa(ps);
		}
	}
}

static int	ft_psh_bck_hlf(t_s *ps, int pshd)
{
// need to write this function to push back half of the to be sorted elements on top of b to a !!!!!!!!!!!!!!!!!!!!!!!!!
}

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
		ft_bck_srt_three(ps)
}

static void ft_srt_bck(t_s *ps, int pshd)
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
