#include "push_swap.h"

int	ft_issorted(t_stacks *ptr_stacks)
{
	int	i;

	i = 1;
	if (ptr_stacks->pos_b == 0)
	{
		while (i < ptr_stacks->pos_a)
		{
			if (ptr_stacks->stack_a[i - 1] > ptr_stacks->stack_a[i])
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_sort(t_stacks *ptr_stacks)
{
// testing
	printf("this is inside of sort.c\n");
        int     j = 0;
        printf("this is stack a\n\n");
        while (j < ptr_stacks->pos_a)
        {
                printf("%d\n", ptr_stacks->stack_a[j]);
                j++;
        }
        printf("\n\nand this is stack c\n\n");
        j = 0;
        while (j < ptr_stacks->pos_a)
        {
                printf("%d\n", ptr_stacks->stack_c[j]);
                j++;
        }
// end of test
	if (ft_issorted(ptr_stacks))
		return ;
}
