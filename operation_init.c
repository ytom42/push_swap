/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:19:14 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/22 14:54:13 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_exec_num(t_stacks *s, int index)
{
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;
	int	ans;

	ans = 0;
	rr = ft_max(s->a[index].ra, s->a[index].rb);
	rrr = ft_max(s->a[index].rra, s->a[index].rrb);
	ra_rrb = s->a[index].ra + s->a[index].rrb;
	rra_rb = s->a[index].rra + s->a[index].rb;
	ans = ft_min(rr, rrr);
	ans = ft_min(ans, ra_rrb);
	ans = ft_min(ans, rra_rb);
	return (ans);
}

static	void	init_ra_rra(t_stacks *s, int i)
{
	t_element	*element;

	element = &s->a[i];
	element->ra = s->a_top - i;
	if (i == s->a_top)
		element->rra = 0;
	else
		element->rra = i;
}

static	void	init_rb_rrb(t_stacks *s, int i, int bottom, int top)
{
	t_element	*element;

	element = &s->a[i];
	if (bottom)
	{
		if ((s->b_top - bottom) == s->b_top)
			element->rb = 0;
		else
			element->rb = s->b_top - bottom;
		if (bottom == s->b_top)
			element->rrb = 0;
		else
			element->rrb = bottom;
		element->exec_num = get_exec_num(s, i);
	}
	else if (top)
	{
		if ((s->b_top - top + 1) == s->b_top)
			element->rb = 0;
		else
			element->rb = s->b_top - top + 1;
		element->rrb = top - 1;
		element->exec_num = get_exec_num(s, i);
	}
}

void	init_exec_len(t_stacks *s, int i)
{
	t_element	*element;

	element = &s->a[i];
	if (s->is_first)
	{
		s->exec_len = element->exec_num;
		s->exec_min_i = i;
		s->is_first = false;
	}
	else if (s->exec_len > element->exec_num)
	{
		s->exec_len = element->exec_num;
		s->exec_min_i = i;
	}
}

void	operation_init(t_stacks *s)
{
	int		i;
	int		index_of_bottom;
	int		index_of_top;

	i = 1;
	s->is_first = true;
	while (i <= s->a_top)
	{
		index_of_bottom = get_bottomindex_b(s, s->a[i].n);
		index_of_top = get_topindex_b(s, s->a[i].n);
		init_ra_rra(s, i);
		init_rb_rrb(s, i, index_of_bottom, index_of_top);
		init_exec_len(s, i);
		i++;
	}
	exec(s);
}
