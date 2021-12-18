/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:32:24 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 18:57:08 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_element *stack, int *top, int n)
{
	stack[*top + 1].n = n;
	*top += 1;
}

int	pop(t_element *stack, int *top)
{
	int	n;

	if (*top <= 0)
		exit(0);
	n = stack[*top].n;
	*top -= 1;
	return (n);
}

void	push_a(t_stacks *s)
{
	int		n;

	n = pop(s->b, &s->b_top);
	push(s->a, &s->a_top, n);
	write(1, "pa\n", 3);
}

void	push_b(t_stacks *s)
{
	int		n;

	n = pop(s->a, &s->a_top);
	push(s->b, &s->b_top, n);
	write(1, "pb\n", 3);
}
