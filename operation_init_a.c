/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_init_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:19:14 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 17:58:41 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_bottomindex_b(t_stacks *s, int n)
{
	int i;
	int ret_index;
	bool first;

	first = true;
	i = 1;
	while (i <= s->b_top)
	{
		if (s->b[i].n < n && first)
		{
			ret_index = i;
			first = false;
		}
		else if ((s->b[i].n < n) && (s->b[i].n > s->b[ret_index].n))
			ret_index = i;
		i++;
	}
	if (first)
		return (0);
	else
		return (ret_index);
}

int get_topindex_b(t_stacks *s, int n)
{
	int i;
	int ret_index;
	bool first;

	first = true;
	i = 1;
	while (i <= s->b_top)
	{
		if (s->b[i].n > n && first)
		{
			ret_index = i;
			first = false;
		}
		else if ((s->b[i].n > n) && (s->b[i].n < s->b[ret_index].n))
			ret_index = i;
		i++;
	}
	if (first)
		return (0);
	else
		return (ret_index);
}

int get_exec_num(t_stacks *s, int index, char c)
{
	int rr;
	int rrr;
	int ra_rrb;
	int rra_rb;
	int ans;

	ans = 0;
	if (c == 'a')
	{
		rr = ft_max(s->a[index].ra, s->a[index].rb);
		rrr = ft_max(s->a[index].rra, s->a[index].rrb);
		ra_rrb = s->a[index].ra + s->a[index].rrb;
		rra_rb = s->a[index].rra + s->a[index].rb;
		ans = ft_min(rr, rrr);
		ans = ft_min(ans, ra_rrb);
		ans = ft_min(ans, rra_rb);
	}
	return (ans);
}

void operation_init_a(t_stacks *s)
{
	int i;
	t_element *element;
	int index_of_bottom;
	int index_of_top;

	i = 1;
	s->is_first = true;
	while (i <= s->a_top)
	{
		element = &s->a[i];
		index_of_bottom = get_bottomindex_b(s, element->n);
		index_of_top = get_topindex_b(s, element->n);
		element->ra = s->a_top - i;
		element->rra = (i == s->a_top ? 0 : i);
		if (index_of_bottom)
		{
			element->rb = ((s->b_top - index_of_bottom) == s->b_top ? 0 : (s->b_top - index_of_bottom));
			element->rrb = (index_of_bottom == s->b_top) ? 0 : index_of_bottom;
			element->exec_num = get_exec_num(s, i, 'a');
		}
		else if (index_of_top)
		{
			element->rb = ((s->b_top - index_of_top + 1) == s->b_top ? 0 : (s->b_top - index_of_top + 1));
			element->rrb = index_of_top - 1;
			element->exec_num = get_exec_num(s, i, 'a');
		}
		
		if (s->is_first)
		{
			s->exec_len = element->exec_num;
			s->is_first = false;
		}
		else if (s->exec_len > element->exec_num)
			s->exec_len = element->exec_num;
		i++;
	}
	exec_a(s);
}
