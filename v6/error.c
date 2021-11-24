#include "push_swap.h"

/*
 * freeing the stacks
 */

void	ft_free(t_s *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps->c);
}

/* printing an error messaage and calling the free function on the stacks */

int	ft_error(t_s *ps)
{
	write(2, "Error\n", 6);
	ft_free(ps);
	return (1);
}

/*
 * checking if there are duplicates
 */

int	ft_isdup(int argc, t_s *ps)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ps->c[i - 1] == ps->c[i])
			return (1);
		i++;
	}
	return (0);
}

/* this function goes through every element of the command-line-arguments
 * and checks if it
 * is within the range of an integer; if not an error is returned to
 * the caller function */

int	ft_isint(int argc, char **argv)
{
	long	nbr;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (1);
		if (ft_strlen(argv[i]) == 11 && argv[i][0] != '-')
			return (1);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

/*
 * this function goes through each command-line-argument and checks if it
 * consists only of numbers and
 * if it starts with a '-'
 * if anything else is discovered the function returns an error to the
 * main function and the program ends
 * it als calls the int checker function to make sure the input only
 * consists of integeres
 */

int	ft_isnum(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 58 && argv[i][j] > 47)
				j++;
			else
				return (1);
		}
		i++;
	}
	if (ft_isint(argc, argv))
		return (1);
	return (0);
}
