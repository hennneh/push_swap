#include "push_swap.h"

void	ft_mmmb(t_s *ps, int pshd)
{
	int	i;

	i = 0;
	ps->mn = ps->b[0];
	ps->mx = ps->b[0];
	while (i < pshd)
	{
		if (ps->b[i] > ps->mx)
			ps->mx = ps->b[i];
		if (ps->b[i] < ps->mn)
			ps->mn = ps->b[i];
		i++;
	}
	ps->md = (ps->mx - ps->mn) / 2 + ps->mn;
}

int	ft_srtmmmb(t_s *ps, int pshd, int *srt)
{
	int	i;
	int	rt;

	rt = 0;
	i = 0;
	while (i < pshd && *srt <= ((ps->mx - ps->mn) / 2))
	{
		if (ps->b[0] > ps->md)
		{
			pa(ps);
			*srt = *srt + 1;
		}
		else
		{
			rb(ps);
			rt++;
		}
		i++;
	}
	return (rt);
}

int	ft_psh_bck_hlf(t_s *ps, int pshd)
{
	int	rt;
	int	srt;
	int	i;

	srt = 0;
	i = 0;
	ft_mmmb(ps, pshd);
	rt = ft_srtmmmb(ps, pshd, &srt);
	while (i < rt)
	{
		rrb(ps);
		i++;
	}
	return (srt);
}
