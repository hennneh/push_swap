#include "push_swap.h"

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
