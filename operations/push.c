/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:32:24 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/17 02:08:15 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *stack, int n)
{
	stack->list[stack->top + 1] = n;
	stack->top += 1;
}

int	pop(t_stack *stack)
{
	int	n;

	if (stack->top <= 0)
	{
		ft_putendl_fd("pop error", 2);/////////////////////
		exit(0);
	}
	n = stack->list[stack->top];
	stack->top -= 1;
	return (n);
}

void	push_a(t_stacks *stacks) //bの先頭をaの先頭に置く
{
	int		n;

	n = pop(stacks->b);
	push(stacks->a, n);
}

void	push_b(t_stacks *stacks) //aの先頭をbの先頭に置く
{
	int		n;

	n = pop(stacks->a);
	push(stacks->b, n);
}
