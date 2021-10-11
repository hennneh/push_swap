#include "push_swap.h"

static int	ft_init(int argc, char **argv, t_stacks stacks)
{
	if (argc < 2 || ft_isnum(argc, argv))
		return (1);
	stacks.pos_a = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.pos_a = 2;
	if (ft_init(argc, argv, stacks))
		return (ft_error());
	return (0);
}
