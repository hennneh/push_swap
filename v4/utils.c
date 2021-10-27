#include "push_swap.h"

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
		nbr = (nbr * 10) + (s[i] - 48);
		i++;
	}
	return (nbr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
