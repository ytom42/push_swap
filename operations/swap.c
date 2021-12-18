/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:31:30 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 18:02:49 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stacks *s)
{
	int		tmp;
	int		top;

	top = s->a_top;
	tmp = s->a[top].n;
	s->a[top].n = s->a[top - 1].n;
	s->a[top - 1].n = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stacks *s)
{
	int		tmp;
	int		top;

	top = s->b_top;
	tmp = s->b[top].n;
	s->b[top].n = s->b[top - 1].n;
	s->b[top - 1].n = tmp;
	write(1, "sb\n", 3);
}

void	swap_a_b(t_stacks *s)
{
	swap_a(s);
	swap_b(s);
	write(1, "ss\n", 3);
}
