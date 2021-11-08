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
int		ft_atoi(const char *nptr);
int		ft_isdup(int argc, t_stacks *ptr_stacks);
void	ft_sort(t_stacks *ptr_stacks);
int		ft_issorted(t_stacks *ptr_stacks);
void	sa(t_stacks *ptr_stacks);
void	sb(t_stacks *ptr_stacks);
void	ss(t_stacks *ptr_stacks);
void	ss(t_stacks *ptr_stacks);
void	pa(t_stacks *ptr_stacks);
void	pb(t_stacks *ptr_stacks);
void	ra(t_stacks *ptr_stacks);
void	rb(t_stacks *ptr_stacks);
void	rr(t_stacks *ptr_stacks);
void	rra(t_stacks *ptr_stacks);
void	rrb(t_stacks *ptr_stacks);
void	rrr(t_stacks *ptr_stacks);
void	ft_sort_three(t_stacks *ptr_stacks);
void	ft_sort_five(t_stacks *ptr_stacks);
void	ft_sort_hundred(t_stacks *ptr_stacks);

#endif
