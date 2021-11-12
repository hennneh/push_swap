#include <stdio.h>				//needs to be removed!!!!!
#include <unistd.h>

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

int	main(int argc, char **argv)
{
	t_s	s;

	s->a = malloc(sizeof(int) * (argc - 1));
	s->b = malloc(sizeof(int) * (argc - 1));
	s->c = malloc(sizeof(int) * (argc - 1));
	s->d = malloc(sizeof(int) * (argc - 1));
	s->e = malloc(sizeof(int) * (argc - 1));
	return (0);
}
