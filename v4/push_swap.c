#include "push_swap.h"

static int	ft_init(int argc, char **argv, t_stacks *ptr_stacks)
{
	if (ft_isnum(argc, argv))
		return (1);
	ft_rank(argc, argv, ptr_stacks);
	if (ft_isdup(argc, ptr_stacks))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stacks	*ptr_stacks;

	stacks.stack_a = malloc(sizeof(int) * (argc - 1));
	stacks.stack_b = malloc(sizeof(int) * (argc - 1));
	stacks.stack_c = malloc(sizeof(int) * (argc - 1));
	ptr_stacks = &stacks;
	if (ft_init(argc, argv, ptr_stacks))
		return (ft_error(ptr_stacks));
	ft_free(ptr_stacks);
	return (0);
}
