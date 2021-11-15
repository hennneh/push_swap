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
	int	*d;
	int	*e;
	int	pa;
	int	pb;
	int	hd;
}	t_s;

void	ft_free(t_s *ps);
int		ft_error(t_s *ps);
int		ft_isdup(int argc, t_s *ps);
int		ft_isint(int argc, char **argv);
int		ft_isnum(int argc, char **argv);
long	ft_atol(char *s);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);

#endif
