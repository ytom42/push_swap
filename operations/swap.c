/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:31:30 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/15 02:25:27 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stacks *stacks) //先頭2つを入れ替え
{
	int		tmp;
	int		*stack;
	int		top;

	stack = stacks->a->list;
	top = stacks->a->top;
	tmp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = tmp;
}

void	swap_b(t_stacks *stacks) //先頭2つを入れ替え
{
	int		tmp;
	int		*stack;
	int		top;

	stack = stacks->b->list;
	top = stacks->b->top;
	tmp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = tmp;
}

void	swap_a_b(t_stacks *stacks) //saとsbを同時に行う
{
	swap_a(stacks);
	swap_b(stacks);
}
