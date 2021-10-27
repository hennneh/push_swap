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

	ptr_stacks = &stacks;
	ptr_stacks->stack_a = malloc(sizeof(int) * (argc - 1));
	ptr_stacks->stack_b = malloc(sizeof(int) * (argc - 1));
	ptr_stacks->stack_c = malloc(sizeof(int) * (argc - 1));
	if (ft_init(argc, argv, ptr_stacks))
		return (ft_error(ptr_stacks));
// testing output
	int i = 0;
	while (i < (argc - 1))
	{
		printf("%d\n", ptr_stacks->stack_c[i]);
		i++;
	}
	if (argc < 3)
	{
		ft_free(ptr_stacks);
		return (0);
	}
	ft_free(ptr_stacks);
	return (0);
}
