#include "push_swap.h"

static int	ft_psh_hlf(t_s *ps, int srt)
{

}

static void	ft_srt(t_s *ps, int srt)
{

}

static void ft_srt_bck(t_s *ps, int pshd)
{

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
