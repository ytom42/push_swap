/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:32:52 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/15 02:31:13 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stacks *stacks) //スタックaのすべての要素を1ずつシフトアップ
{
	int		i;
	int		tmp;
	int		*stack;

	stack = stacks->a->list;
	i = stacks->a->top;
	tmp = stack[i];
	while (i > BOTTOM)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[BOTTOM] = tmp;
}

void	rotate_b(t_stacks *stacks) //スタックbの全ての要素を1ずつシフトアップ
{
	int		i;
	int		tmp;
	int		*stack;

	stack = stacks->b->list;
	i = stacks->b->top;
	tmp = stack[i];
	while (i > BOTTOM)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[BOTTOM] = tmp;
}

void	rotate_a_b(t_stacks *stacks) //ra と rb を同時に行う
{
	rotate_a(stacks);
	rotate_b(stacks);
}