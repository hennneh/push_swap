#include "push_swap.h"

static void	ft_transfer(int argc, char **argv, t_stacks *ptr_stacks)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (argc - 1))
		{
			if (ft_atoi(argv[i]) == ptr_stacks->stack_c[j])
			{
				ptr_stacks->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	ft_init(int argc, char **argv, t_stacks *ptr_stacks)
{
	if (ft_isnum(argc, argv))
		return (1);
	ft_rank(argc, argv, ptr_stacks);
	if (ft_isdup(argc, ptr_stacks))
		return (1);
	ft_transfer(argc, argv, ptr_stacks);
	// testing
	int	i = 0;
	while (i < (argc - 1))
	{
		printf("%d\n", ptr_stacks->stack_a[i]);
		i++;
	}
	//end of test
	ptr_stacks->pos_a = argc - 1;
	ptr_stacks->pos_b = 0;
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
	if (argc < 3)
	{
		ft_free(ptr_stacks);
		return (0);
	}
	ft_free(ptr_stacks);
	return (0);
}
