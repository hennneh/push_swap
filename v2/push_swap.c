#include "push_swap.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

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

int	ft_atol(*s)
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

int	ft_neg_input(*s)
{
	long	nbr;

	nbr = ft_atol(*s);
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
		j = 0;
		if (ft_strlen(argv[i] > 11))
			return (0);
		if (ft_strlen(argv[i] == 11 && argv[i][0] != '-'))
			return (0);
		else if (!ft_neg_input(argv[i]))
			return (0);
											// add ft_neg_input
											// finish input check for ints
	}
	return (1);
}

int	ft_init(int argc, char **argv)
{
	if (!ft_is_int(argc, argv))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (!ft_init(argc, argv))
		return (ft_error_msg());
	return (0);
}
