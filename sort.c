/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:34:39 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/19 09:27:08 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b);
void	vars_init(t_stacks *stacks, t_vars *vars);
int		check(t_stacks *stacks);
int		get_min(t_stack *stack, t_vars *vars);
int		get_rev(t_stack *stack);

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stacks stacks;
	t_vars vars;

	stacks.a = stack_a;
	stacks.b = stack_b;
	//////////////////////////
	system("clear");
	print_stack(&stacks);
	system("rm log.txt");
	system("touch log.txt");
	int fd = open("log.txt", O_WRONLY);
	/////////////////////////
	while (1)
	{
		vars_init(&stacks, &vars);

		if (stacks.a->list[stacks.a->top] >= stacks.b->list[stacks.b->top] && vars.rev == 0)
			test_sort(&stacks, "pa", fd);
		else if (vars.min == stacks.a->list[stacks.a->top])
			test_sort(&stacks, "pb", fd);
		else
		{
			// test_sort(&stacks, "ra", fd);
			if (vars.r <= vars.rr)
				test_sort(&stacks, "ra", fd);
			else
				test_sort(&stacks, "rra", fd);
		}
	}
}

void	vars_init(t_stacks *stacks, t_vars *vars)
{
	////////////////////////////////
	static int k = 1;
	if (check(stacks) == 0)
	{
		printf("CLEAR\n");
		printf("%d回\n", k);
		exit(0);
	}
	////////////////////////////////

	vars->min_a = get_min(stacks->a, vars); // vars->r & vars->rr
	vars->rev_a = get_rev(stacks->a);

	////////////////////////////////
	printf("%d回目\n\n\n", k);
	k++;
	print_vars(stacks, vars);
	////////////////////////////////
}

int	check(t_stacks *stacks)
{
	int		i;
	int		*stack;

	i = stacks->a->top;
	stack = stacks->a->list;
	while (i > 1)
	{
		if (stack[i] > stack[i - 1])
			return (1); 
		i--;
	}
	if (stacks->b->top == 0)
		return (0);
	else
		return (1);
}

int	get_min(t_stack *stack, t_vars *vars)
{
	int		i;
	int		min;

	if (stack->top == 0)
	{
		ft_putendl_fd("get_min: ERROR", 2);
		exit(0);
	}
	min = stack->list[1];
	vars->r = stack->top - 1;
	vars->rr = 1;
	if (stack->top == 1)
	{
		vars->r = 0;
		vars->rr = 0;
		return (min);
	}
	i = 2;
	while (i <= stack->top)
	{
		if (min > stack->list[i])
		{
			min = stack->list[i];
			vars->r = stack->top - i;
			vars->rr = i;
			if (i == stack->top)
			{
				vars->r = 0;
				vars->rr = 0;
			}
		}
		i++;
	}
	return (min);
}

int	get_rev(t_stack *stack)
{
	int		i;
	int		rev;
	int		tmp;

	if (stack->top <= 1)
		return (0);
	rev = 0;
	tmp = stack->list[1];
	i = 2;
	while (i <= stack->top)
	{
		if (tmp < stack->list[i])
			rev++;
		tmp = stack->list[i];
		i++;
	}
	return (rev);
}
