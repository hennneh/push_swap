#include "push_swap.h"

static void	ft_hat(int *cnt, t_stacks *ptr_stacks, int head)
{
	int	i;

	while (head < ptr_stacks->pos_a)
	{
		i = head + 1;
		if (i == ptr_stacks->pos_a)
			i = 0;
		while (i != head)
		{
			if (i == 0)
			{
				if (ptr_stacks->stack_a[i] > ptr_stacks->stack_a[ptr_stacks->pos_a - 1]
					&& ptr_stacks->stack_a[i] > ptr_stacks->stack_a[head])
					cnt[head]++;
			}
			else if (ptr_stacks->stack_a[i] > ptr_stacks->stack_a[i - 1]
				&& ptr_stacks->stack_a[i] > ptr_stacks->stack_a[head])
				cnt[head]++;
			i++;
			if (i == ptr_stacks->pos_a)
				i = 0;
		}
		head++;
	}
}

static void	ft_cnt(int *cnt, t_stacks *ptr_stacks, int head)
{
	while (head < ptr_stacks->pos_a)
	{
		cnt[head] = 1;
		head++;
	}
}

static void	ft_loop_back(t_stacks *ptr_stacks, int *head)
{
	*head = 0;
	if (ptr_stacks->stack_a[*head] > ptr_stacks->stack_a[ptr_stacks->pos_a - 1])
		ptr_stacks->d[ptr_stacks->stack_a[0]] = 1;
	else
		ptr_stacks->d[ptr_stacks->stack_a[0]] = 0;
}

static void	ft_index(t_stacks *ptr_stacks, int head)
{
	int	i;

	i = ptr_stacks->pos_a - 1;
	ptr_stacks->d[ptr_stacks->stack_a[head]] = 1;
	head++;
	while (i > 0)
	{
		if (head == ptr_stacks->pos_a)
			ft_loop_back(ptr_stacks, &head);
		else if (ptr_stacks->stack_a[head] > ptr_stacks->stack_a[head - 1])
			ptr_stacks->d[ptr_stacks->stack_a[head]] = 1;
		else
			ptr_stacks->d[ptr_stacks->stack_a[head]] = 0;
		head++;
		i--;
	}
}

static int	ft_find_head(t_stacks *ptr_stacks)
{
	int	i;
	int	*cnt;
	int	head;

	cnt = malloc(sizeof(int) * ptr_stacks->pos_a);
	ft_cnt(cnt, ptr_stacks, 0);
	ft_hat(cnt, ptr_stacks, 0);
	i = 1;
	head = 0;
	while (i < ptr_stacks->pos_a)
	{
		if (cnt[i] > cnt[head])
			head = i;
		else if (cnt[i] == cnt[head])
		{
			if (ptr_stacks->stack_a[i] < ptr_stacks->stack_a[head])
				head = i;
		}
		i++;
	}
	ft_index(ptr_stacks, head);
	free(cnt);
	return (head);
}

void	ft_move(t_stacks *ptr_stacks)
{
	int	i;

	i = 0;
	while (i < ptr_stacks->pos_a)
	{
		if (ptr_stacks->d[ptr_stacks->stack_a[0]] == 0)
			pb(ptr_stacks);
		else
			ra(ptr_stacks);
		i++;
	}
}

int	ft_find_pos(t_stacks *ptr_stacks)
{
	int	pos;

	pos = 0;
	while (ptr_stacks->stack_a[pos] != ptr_stacks->stack_b[0] - 1)
		pos++;
	return (pos + 1);
}

void	ft_back(t_stacks *ptr_stacks)
{
	int	pos;

	while (ptr_stacks->pos_b != 0)
	{
		pos = ft_find_pos(ptr_stacks);
		if (ptr_stacks->pos_a / 2 > pos)
		{
			while (pos > 0)
			{
				ra(ptr_stacks);
				pos--;
			}
		}
		else
		{
			pos = ptr_stacks->pos_a - pos;
			while (pos > 0)
			{
				rra(ptr_stacks);
				pos--;
			}
		}
		pa(ptr_stacks);
	}
}

void	ft_top(t_stacks *ptr_stacks)
{
	int	pos;

	pos = 0;
	while (ptr_stacks->stack_a[pos] != 0)
		pos++;
	if (ptr_stacks->pos_a / 2 > pos)
	{
		while (pos > 0)
		{
			ra(ptr_stacks);
			pos--;
		}
	}
	else
	{
		pos = ptr_stacks->pos_a - pos;
		while (pos > 0)
		{
			rra(ptr_stacks);
			pos--;
		}
	}
}

void	ft_sort_hundred(t_stacks *ptr_stacks)
{
	int	i;

	i = ft_find_head(ptr_stacks);
	ft_move(ptr_stacks);
	ft_back(ptr_stacks);
	ft_top(ptr_stacks);
	//testing aölsdkjfaölskjdfölaksjdfölkj
	i = 0;
	while (i < ptr_stacks->pos_a)
	{
		printf("%d\n", ptr_stacks->stack_a[i]);
		i++;
	}
	i = 0;
	printf("\n\nand now the sorted stack_a\n\n");
	while (i < ptr_stacks->pos_a)
	{
		printf("%d\n", ptr_stacks->stack_a[i]);
		i++;
	}
	//test is over aslödkfjöalskdjfölaksjdf
}
