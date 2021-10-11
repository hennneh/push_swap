#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_c;
	int	pos_a;
	int	pos_b;
}				t_stacks;

int	ft_error(void);
int	ft_isnum(int argc, char **argv);

#endif
