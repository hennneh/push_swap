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

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_init(int argc, char **argv)
{
	return (1);
}

int	main(int argc, char **argv)
{
	if (!ft_init(argc, argv))
		return (ft_error());
	return (0);
}
