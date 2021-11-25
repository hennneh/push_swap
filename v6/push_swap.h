#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //NEEDS TO BE REMOVED AÖLSDKJFALÖSKDJFÖALSKJDFÖLKAJSDÖFLKJASDÖLFKJAÖSLDKJFÖALSDKJF
# include <unistd.h>
# include <stdlib.h>

typedef struct s_s
{
	int	*a;
	int	*b;
	int	*c;
	int	pa;
	int	pb;
}	t_s;

void	sa(t_s *ps);
void	sb(t_s *ps);
void	ss(t_s *ps);
void	ss(t_s *ps);
void	pa(t_s *ps);
void	pb(t_s *ps);
void	ra(t_s *ps);
void	rb(t_s *ps);
void	rr(t_s *ps);
void	rra(t_s *ps);
void	rrb(t_s *ps);
void	rrr(t_s *ps);
void	ft_free(t_s *ps);
int		ft_error(t_s *ps);
int		ft_isdup(int argc, t_s *ps);
int		ft_isint(int argc, char **argv);
int		ft_isnum(int argc, char **argv);
long	ft_atol(char *s);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
void	ft_sort(t_s *ps);
void	ft_sort_five(t_s *ps);
int		ft_issorted(t_s *ps);
void	ft_sort_rest(t_s *ps, int srt);
void	ft_thrtwoone(t_s *ps);
void	ft_onethrtwo(t_s *ps);
void	ft_twothrone(t_s *ps);
void	ft_twoonethr(t_s *ps);
void	ft_thronetwo(t_s *ps);
void	ft_onetwothr(t_s *ps);

#endif
