#include <stdio.h>				//needs to be removed!!!!!
#include <unistd.h>
#include <stdlib.h>

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

/*
 * this function goes through every element of the command-line-arguments and checks if it
 * is within the range of an integer; if not an error is returned to the caller function
 */

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
 * this function goes through each command-line-argument and checks if it consists only of numbers and
 * if it starts with a '-'
 * if anything else is discovered the function returns an error to the main function and the program ends
 * it als calls the int checker function to make sure the input only consists of integeres
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

/*
 * function that initializes the counter variables for the position inside stack a and b
 * it also checks if the input is valid by calling functions to check if the input
 * only consists of numbers/ints as well as checking for duplicates
 * then it replaces the given input with the calculated ranks and puts them into stack a
 */

int	ft_init(int argc, char **argv, t_s *ps)
{
	if (ft_isnum(argc, argv))
		return (1);
	ft_rank(argc, argv, ps);
	if (ft_isdup(argc, ps))
		return (1);
	ft_transfer(argc, argv, ps);
	ps->pa = argc - 1;
	ps->pb = 0;
	return (0);
}

/* 
 * main function that is initializing the arrays and calling every other function
 */

int	main(int argc, char **argv)
{
	t_s	s;
	t_s	ps;

	ps = &s;
	s->a = malloc(sizeof(int) * (argc - 1));
	s->b = malloc(sizeof(int) * (argc - 1));
	s->c = malloc(sizeof(int) * (argc - 1));
	s->d = malloc(sizeof(int) * (argc - 1));
	s->e = malloc(sizeof(int) * (argc - 1));

	if (ft_init(argc, argv, ps))
		return (ft_error(ps));
	return (0);
}
