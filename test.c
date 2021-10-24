#include "push_swap.h"
#include <curses.h>

void	test_start(t_stacks *stacks, t_vars *vars)
{
	system("clear");
	print_stack(stacks, vars);
	system("rm log.txt");
	system("touch log.txt");
	vars->fd = open("log.txt", O_WRONLY);
}

void	test_sort(t_stacks *stacks, t_vars *vars, char *str)
{
	char	input[10];
	ft_strlcpy(input, str, 4);
	printf("next-> %s\n", input);
	while(getchar() != '\n');

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

	ft_putendl_fd(input, vars->fd);
	system("clear");
	print_stack(stacks, vars);
}

void	print_stack(t_stacks *stacks, t_vars *vars)
{
	int	i;
	
	printf("===b====\n");
	i = 1;
	while (i <= stacks->b->top)
	{
		printf("[%d] %d", i, stacks->b->list[i]);
		if (stacks->b->list[i] == vars->minimum)
			printf(" <- all.minimum");
		printf("\n");
		i++;
	}
	printf("======== top[%d]\n", stacks->b->top);
	printf("===a====\n");
	i = stacks->a->top;
	while (i > 0)
	{
		printf("[%d] %d", i, stacks->a->list[i]);
		if (stacks->a->list[i] == vars->minimum)
			printf(" <- all.minimum");
		else if (stacks->a->list[i] == vars->a_bottom)
			printf(" <- a.bottom");
		printf("\n");
		i--;
	}
	printf("======== top[%d]\n", stacks->a->top);
	i = stacks->sorted->top;
	while (i > 0)
	{
		printf("%d ", stacks->sorted->list[i]);
		i--;
	}
	printf("\n");
	printf("tmp.top = %d\n", stacks->tmp->top);
	i = stacks->tmp->top;
	while (i > 0)
	{
		printf("%d ", stacks->tmp->list[i]);
		i--;
	}
}

void	print_vars(t_stacks *stacks, t_vars *vars)
{
	printf("\n---------------------\n");
	printf("%d回目\n", vars->k++);
	printf("---------------------\n");
	printf("target = %d\n", stacks->sorted->list[stacks->sorted->next]);
	printf("minimum = %d\n", vars->minimum);
	if (vars->phase == START)
		printf("phase = START\n\n");
	else if (vars->phase == ADD_A)
		printf("phase = ADD_A\n\n");
	else if (vars->phase == ADD_B)
		printf("phase = ADD_B\n\n");

	printf("b[top] = %d\n", stacks->b->list[stacks->b->top]);
	printf("b.min = %d\n", vars->b_min);
	printf("b.top_tmp = %d\n", vars->b_top_tmp);
	printf("\n");

	printf("a[top] = %d\n", stacks->a->list[stacks->a->top]);
	printf("a[bottom] = %d\n", vars->a_bottom);
	printf("a.min = %d\n", vars->a_min);
	printf("---------------------\n");
}
