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

void	ft_sort_three(t_stacks *ptr_stacks)
{
	if (ptr_stacks->stack_a[0] == 2 && ptr_stacks->stack_a[1] == 1)
	{
		ra(ptr_stacks);
		ra(ptr_stacks);
	}
	else if (ptr_stacks->stack_a[0] == 0 && ptr_stacks->stack_a[1] == 2)
	{
		rra(ptr_stacks);
		sa(ptr_stacks);
	}
	else if (ptr_stacks->stack_a[0] == 1 && ptr_stacks->stack_a[1] == 2)
		rra(ptr_stacks);
	else if (ptr_stacks->stack_a[0] == 1 && ptr_stacks->stack_a[1] == 0)
		sa(ptr_stacks);
	else if (ptr_stacks->stack_a[0] == 2 && ptr_stacks->stack_a[1] == 0)
		ra(ptr_stacks);
}

void	ft_sort(t_stacks *ptr_stacks)
{/*
// testing
	printf("this is inside of sort.c\n");						//test
        int     j = 0;											//test
        printf("this is stack a\n\n");							//test
        while (j < ptr_stacks->pos_a)							//test
        {														//test
                printf("%d\n", ptr_stacks->stack_a[j]);			//test
                j++;											//test
        }														//test
        printf("\n\nand this is stack c\n\n");					//test
        j = 0;													//test
        while (j < ptr_stacks->pos_a)							//test
        {														//test
                printf("%d\n", ptr_stacks->stack_c[j]);			//test
                j++;											//test
        }														//test
// end of test */
	if (ft_issorted(ptr_stacks))
		return ;
	if (ptr_stacks->pos_a == 3)
		ft_sort_three(ptr_stacks);
/*	else if (ptr_stacks->pos_a == 5)							//not implemented
		ft_sort_five(ptr_stacks);								//not implemented
	else if (ptr_stacks->pos_a == 100)							//not implemented
		ft_sort_hundred(ptr_stacks);							//not implemented
	else if (ptr_stacks->pos_a == 500)							//not implemented
		ft_sort_fivehundred(ptr_stacks);						//not implemented
	else														//not implemented
		ft_sort_rest(ptr_stacks);*/								//not implemented
/*	//another test												//test
	printf("and now the sorted array\n");						//test
	j = 0;														//test
	while (j < ptr_stacks->pos_a)								//test
	{															//test
		printf("%d\n", ptr_stacks->stack_a[j]);					//test
			j++;												//test
	}															//test
	//end of test		*/										//test
	printf("before sorting:.\n");
	int	j = 0;
	while (j < ptr_stacks->pos_a)
	{
		printf("%d\n", ptr_stacks->stack_a[j]);
		j++;
	}
	ra(ptr_stacks);
	j = 0;
	printf("after ra\n");
	while (j < ptr_stacks->pos_a)
	{
		printf("%d\n", ptr_stacks->stack_a[j]);
		j++;
	}
}
