#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atol(char *s)
{
	size_t	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			sign *= -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	return (num * sign);
}

int	ft_error_msg(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_neg_input(char *s)
{
	long	nbr;

	nbr = ft_atol(s);
	if (nbr < -2147483648)
		return (0);
	return (1);
}

int	ft_is_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			return (0);
		if (ft_strlen(argv[i]) == 11 && argv[i][0] != '-')
			return (0);
		else if (!ft_neg_input(argv[i]))
			return (0);
		if (ft_strlen(argv[i]) == 10 && ft_atol(argv[i]) > 2147482647)
			return (0);
		i++;
	}
	return (1);
}

void	ft_rearrange(int *array, int i, int j)
{
	int	temp;

	while (i != j)
	{
		temp = array[j - 1];
		array[j - 1] = array[j];
		array[j] = temp;
		j--;
	}
}

int	ft_check_double(int *array, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (j < argc - 1)
	{
		while (array[i] < array[j] && j < argc - 1)
			j++;
		if (array[i] == array[j])
			return (0);
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_sort(int *array, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (i < j)
			j++;
		i++;
		if (array[i - 1] > array[j])
		{
			ft_rearrange(array, i, j);
			i = 0;
		}
	}
	if (!ft_check_double(array, argc))
		return (0);
	return (1);
}

int	ft_presort(int *array, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if (!ft_sort(array, argc))
		return (0);
	return (1);
}

int	ft_init(int argc, char **argv)
{
	int	*array;

	if (!ft_is_int(argc, argv))
		return (0);
	array = malloc(argc - 1 * sizeof(int));
	if (!ft_presort(array, argc, argv))
		return (0);
	int i = 0;
	while (i < argc - 1)
	{
		printf("%d\n", array[i]);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!ft_init(argc, argv))
		return (ft_error_msg());
	return (0);
}
