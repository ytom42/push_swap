/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:47:26 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/09 17:55:49 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_n2(t_stacks *s)
{
	int	i;
	int	ret;

	if (s->a_min != s->a[1].n)
	{
		ret = s->a[1].n;
		i = 2;
	}
	else
	{
		ret = s->a[2].n;
		i = 3;
	}
	while (i <= s->a_top)
	{
		if (ret > s->a[i].n && s->a_min != s->a[i].n)
			ret = s->a[i].n;
		i++;
	}
	return (ret);
}

static	void	three(t_stacks *s)
{
	if (!check_stack(s))
		return ;
	if (s->a_min == s->a[1].n)
	{
		if (s->a_max == s->a[3].n)
			swap_a(s);
		rev_rotate_a(s, true);
	}
	else
	{
		if (s->a_max == s->a[2].n || s->a_max == s->a[1].n)
			swap_a(s);
		if (s->a_max != s->a[1].n)
			rotate_a(s, true);
	}
}

static	void	four_five(t_stacks *s, int len)
{
	int	n1;
	int	n2;

	n1 = s->a_min;
	n2 = 0;
	if (len == 5)
		n2 = get_n2(s);
	while (s->a_top > 3)
	{
		if ((s->a[s->a_top].n == n1) || (s->a[s->a_top].n == n2 && len == 5))
			push_b(s);
		else
			rotate_a(s, true);
	}
	if (len == 5 && s->b[1].n > s->b[2].n)
		swap_b(s);
	update_amax_amin(s);
	three(s);
	while (s->b_top > 0)
		push_a(s);
}

void	five_or_less(t_stacks *s)
{
	int	len;

	len = s->stack_len;
	if (check_stack(s))
		return ;
	else if (len == 2)
		swap_a(s);
	else if (len == 3)
		three(s);
	else if (len == 4 || len == 5)
		four_five(s, len);
}
