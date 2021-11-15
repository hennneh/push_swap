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

long	ft_atol(char *s)
{
	long	nbr;
	int		i;
	int		sign;

	nbr = 0;
	i = 0;
	sign = 1;
	if (s[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (s[i])
	{
		nbr = nbr * 10 + s[i] - '0';
		i++;
	}
	return (nbr * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			sign *= -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

/*
 * freeing the stacks
 */

void	ft_free(t_s *ps)
{
	free(ps->a);
	free(ps->b);
	free(ps->c);
	free(ps->d);
}

/*
 * printing an error messaage and calling the free function on the stacks
 */

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

/*
 * iterating through the input and replacing it with the position/rank it has in stack c
 * while shifting it into stack a
 */

void	ft_transfer(int argc, char **argv, t_s *ps)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < (argc - 1))
		{
			if (ft_atoi(argv[i]) == ps->c[j])
			{
				ps->a[i - 1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

/*
 * iterating through every command line argument and putting it into stack c
 * then sorting stack c with bubble sort
 */

void	ft_rank(int argc, char **argv, t_s *ps)
{
	int	i;
	int	temp;

	i = 1;
	while (i < argc)
	{
		ps->c[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 1;
	while (i < (argc - 1))
	{
		if (ps->c[i - 1] > ps->c[i])
		{
			temp = ps->c[i];
			ps->c[i] = ps->c[i - 1];
			ps->c[i - 1] = temp;
			i = 0;
		}
		i++;
	}
}

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
	t_s	*ps;

	ps = &s;
	ps->a = malloc(sizeof(int) * (argc - 1));
	ps->b = malloc(sizeof(int) * (argc - 1));
	ps->c = malloc(sizeof(int) * (argc - 1));
	ps->d = malloc(sizeof(int) * (argc - 1));
	ps->e = malloc(sizeof(int) * (argc - 1));

	if (ft_init(argc, argv, ps))
		return (ft_error(ps));
	return (0);
}
