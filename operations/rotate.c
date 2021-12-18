/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:32:52 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 18:02:42 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stacks *s, bool is_print)
{
	int		i;
	int		tmp;

	i = s->a_top;
	tmp = s->a[i].n;
	while (i > 1)
	{
		s->a[i].n = s->a[i - 1].n;
		i--;
	}
	s->a[1].n = tmp;
	if (is_print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stacks *s, bool is_print)
{
	int		i;
	int		tmp;

	i = s->b_top;
	tmp = s->b[i].n;
	while (i > 1)
	{
		s->b[i].n = s->b[i - 1].n;
		i--;
	}
	s->b[1].n = tmp;
	if (is_print)
		write(1, "rb\n", 3);
}

void	rotate_a_b(t_stacks *s)
{
	rotate_a(s, false);
	rotate_b(s, false);
	write(1, "rr\n", 3);
}