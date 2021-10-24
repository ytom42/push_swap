/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:34:39 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/24 16:06:52 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check(t_stacks *stacks, t_vars *vars);
int		check_low(t_stack *stack, int n);
void	get_a_bottom(t_stacks *stacks, t_vars *vars);

void	sort(t_stacks *stacks, t_vars *vars)
{
	t_stack *a;
	t_stack *b;

	a = stacks->a;
	b = stacks->b;
	vars->phase = START;
	test_start(stacks, vars); //test-------------
	while (1)
	{
		check(stacks, vars);
		vars_init(stacks, vars);

		if (a->list[a->top] == stacks->sorted->list[stacks->sorted->next] && vars->phase != START)
		{
			test_sort(stacks, vars, "ra");
			stacks->sorted->next -= 1;
		}
		else if (b->top != 0 && b->list[b->top] == stacks->sorted->list[stacks->sorted->next] && vars->phase != START)
			test_sort(stacks, vars, "pa");
		else if (stacks->a->list[stacks->a->top - 1] != vars->minimum && stacks->a->list[stacks->a->top] > stacks->a->list[stacks->a->top - 1] && vars->phase == ADD_A)
			test_sort(stacks, vars, "sa");
		else if (vars->phase == START)
		{
			if (check_low(stacks->sorted, a->list[a->top]) == 1)
				test_sort(stacks, vars, "pb");
			else
				test_sort(stacks, vars, "ra");
		}
		else if (vars->phase == ADD_A)
		{
			if (!(check_low(stacks->tmp, b->list[b->top])))
				test_sort(stacks, vars, "pa");
			else
				test_sort(stacks, vars, "rb");
		}
		else if (vars->phase == ADD_B)
		{
			test_sort(stacks, vars, "pb");
		}
		
		// フェーズ切り替え
		if (vars->phase == START)
		{
			if (stacks->a->list[stacks->a->top] == vars->a_bottom)
			{
				vars->phase = ADD_A;
				vars->a_bottom = stacks->a->list[1];
				vars->b_top_tmp = stacks->b->top;
				single_stack_sort(stacks->tmp, stacks->b);
			}
		}
		else if (vars->phase == ADD_B)
		{
			if (stacks->a->list[stacks->a->top] == vars->minimum)
			{
				vars->phase = ADD_A;
				vars->b_top_tmp = stacks->b->top;
				single_stack_sort(stacks->tmp, stacks->b);
			}
		}
		else if (vars->phase == ADD_A)
		{
			if (stacks->b->top == 0)
			{
				vars->phase = ADD_B;
				get_a_bottom(stacks, vars);
			}
		}
	}
}

int	check(t_stacks *stacks, t_vars *vars)
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
	{
		printf("\n\nCLEAR\n");
		printf("%d回\n", vars->k - 1);
		exit(0);
	}
	else
		return (1);
}

int	check_low(t_stack *stack, int n)
{
	int	i;
	int	top;

	top = stack->top;
	i = ((top + 1) / 2) + 1;
	while (i <= top)
	{
		if (stack->list[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	get_a_bottom(t_stacks *stacks, t_vars *vars)
{
	int	i;
	i = stacks->a->top;
	while (stacks->a->list[i] != vars->minimum)
		i--;
	vars->a_bottom = stacks->a->list[i + 1];
}
