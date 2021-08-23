#include <stdio.h>

static int	create_stack(int argc, char **argv, int *stack_a)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (argv[i][0] >= '0' && argv[i][0] <= '9')
		{
			stack_a[j] = argv[i][0] - 48;
			i++;
			j++;
		}
		else
			return (-1);
	}
	return (i - 1);
}

int	main(int argc, char **argv)
{
	int	len;
	int	stack_a[argc - 1];
	int stack_b[argc - 1];
	len = create_stack(argc, argv, stack_a);
	printf("arg_count: %d\n", len);
	printf("stack[0]: %d\n", stack_a[0]);
	return (0);
}
