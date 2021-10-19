#include "push_swap.h"
#include <curses.h>

void	test_sort(t_stacks *stacks, char *str, int fd)
{
	char	input[10];

	ft_strlcpy(input, str, 4);

	char	tmp[10];
	printf("\ninput = %s\n", input);
	scanf("%s", tmp);

	if (!ft_strncmp(input, "pa", 3))
		push_a(stacks);
	else if (!ft_strncmp(input, "pb", 3))
		push_b(stacks);
	else if (!ft_strncmp(input, "sa", 3))
		swap_a(stacks);
	else if (!ft_strncmp(input, "sb", 3))
		swap_b(stacks);
	else if (!ft_strncmp(input, "ss", 3))
		swap_a_b(stacks);
	else if (!ft_strncmp(input, "ra", 3))
		rotate_a(stacks);
	else if (!ft_strncmp(input, "rb", 3))
		rotate_b(stacks);
	else if (!ft_strncmp(input, "rr", 3))
		rotate_a_b(stacks);
	else if (!ft_strncmp(input, "rra", 3))
		rev_rotate_a(stacks);
	else if (!ft_strncmp(input, "rrb", 3))
		rev_rotate_b(stacks);
	else if (!ft_strncmp(input, "rrr", 3))
		rev_rotate_a_b(stacks);
	else
		return;

	ft_putendl_fd(input, fd);
	system("clear");
	print_stack(stacks);
}

void	print_stack(t_stacks *stacks)
{
	int	i;
	
	printf("===b====\n");
	i = 1;
	while (i <= stacks->b->top)
	{
		printf("%d\n", stacks->b->list[i]);
		i++;
	}
	printf("======== top[%d]\n", stacks->b->top);
	printf("===a====\n");
	i = stacks->a->top;
	while (i > 0)
	{
		printf("%d\n", stacks->a->list[i]);
		i--;
	}
	printf("======== top[%d]\n", stacks->a->top);
}

void	print_vars(t_stacks *stacks, t_vars *vars)
{
	printf("a.min = %d\n", vars->min_a);
	printf("a.rev = %d\n", vars->rev_a);
	printf("a.r = %d\n", vars->r);
	printf("a.rr = %d\n", vars->rr);
	printf("a[top] = %d\n\n", stacks->a->list[stacks->a->top]);

	printf("b.min = %d\n", vars->min_b);
	printf("b.rev = %d\n", vars->rev_b);
	printf("b[top] = %d\n\n", stacks->b->list[stacks->b->top]);
}
