#include "push_swap.h"

static int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	ft_isnum(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && argv[i][j] > 47 && argv[i][j] < 58)
			j++;
		if (argv[i][j - 1] > 57 || argv[i][j - 1] < 48)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_init(int argc, char **argv, t_stacks stacks)
{
	if (argc < 2 || ft_isnum(argc, argv))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (ft_init(argc, argv, stacks))
		return (ft_error());
	return (0);
}
