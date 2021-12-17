/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:33:34 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/17 10:35:59 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate_a(t_stacks *s, bool is_print) //スタックaのすべての要素を1ずつシフトダウン
{
	int		i;
	int		tmp;

	tmp = s->a[1].n;
	i = 1;
	while (i < s->a_top)
	{
		s->a[i].n = s->a[i + 1].n;
		i++;
	}
	s->a[i].n = tmp;
	if (is_print)
		write(fd, "rra\n", 4);
}

void	rev_rotate_b(t_stacks *s, bool is_print) //スタックbの全ての要素を1ずつシフトダウン
{
	int		i;
	int		tmp;

	tmp = s->b[1].n;
	i = 1;
	while (i < s->b_top)
	{
		s->b[i].n = s->b[i + 1].n;
		i++;
	}
	s->b[i].n = tmp;
	if (is_print)
		write(fd, "rrb\n", 4);
}

void	rev_rotate_a_b(t_stacks *stacks) //rraとrrbを同時に行う
{
	rev_rotate_a(stacks, false);
	rev_rotate_b(stacks, false);
	write(fd, "rrr\n", 4);
}
