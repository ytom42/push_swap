/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:26:16 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/24 15:59:29 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vars_init(t_stacks *stacks, t_vars *vars)
{
	vars->a_min = get_min(stacks->a);
	vars->b_min = get_min(stacks->b);
	vars->a_len = stacks->a->top;
	vars->b_len = stacks->b->top;

	print_vars(stacks, vars); //test---------------------
}

int	get_min(t_stack *stack)
{
	int		i;
	int		min;

	if (stack->top == 0)
	{
		return (0);
		// ft_putendl_fd("get_min: ERROR", 2);
		// exit(0);
	}
	min = stack->list[1];
	if (stack->top == 1)
		return (min);
	i = 2;
	while (i <= stack->top)
	{
		if (min > stack->list[i])
			min = stack->list[i];
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
