/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:33:34 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/15 02:33:48 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(t_stacks *stacks) //スタックaのすべての要素を1ずつシフトダウン
{
	int		i;
	int		top;
	int		tmp;
	int		*stack;

	stack = stacks->a->list;
	top = stacks->a->top;
	tmp = stack[BOTTOM];
	i = 1;
	while (i < top)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

void	rev_rotate_b(t_stacks *stacks) //スタックbの全ての要素を1ずつシフトダウン
{
	int		i;
	int		top;
	int		tmp;
	int		*stack;

	stack = stacks->b->list;
	top = stacks->b->top;
	tmp = stack[BOTTOM];
	i = 1;
	while (i < top)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

void	rev_rotate_a_b(t_stacks *stacks) //rraとrrbを同時に行う
{
	rev_rotate_a(stacks);
	rev_rotate_b(stacks);
}
