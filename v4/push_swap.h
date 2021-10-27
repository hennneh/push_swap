#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_c;
	int	pos_a;
	int	pos_b;
}		t_stacks;

int		ft_error(t_stacks *ptr_stacks);
int		ft_isnum(int argc, char **argv);
void	ft_free(t_stacks *ptr_stacks);
long	ft_atol(char *s);
size_t	ft_strlen(const char *str);
void	ft_rank(int argc, char **argv, t_stacks *ptr_stacks);
int		ft_atoi(const char *nptr);

#endif
