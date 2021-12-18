/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:34:39 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 18:08:19 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a_to_b(t_stacks *s)
{
	if (s->b_top <= 1)
	{
		push_b(s);
		return ;
	}
	else if ((s->b_top == 2) && (s->b[1].n > s->b[2].n))
		swap_b(s);
	else
	{
		operation_init_a(s);
	}
}

void b_to_a(t_stacks *s)
{
	int i;
	int top_index;

	i = 0;
	top_index = get_top_index_b(s);
	if ((top_index * 2) > s->b_top)
	{
		while (i < s->b_top - top_index)
		{
			rotate_b(s, true);
			i++;
		}
	}
	else
	{
		while (i < top_index)
		{
			rev_rotate_b(s, true);
			i++;
		}
	}
	while (s->b_top > 0)
		push_a(s);
	return ;
}

int get_n2(t_stacks *s)
{
	int i;
	int ret;

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

void update_amax_amin(t_stacks *s)
{
	int i;

	i = 1;
	s->a_max = s->a[i].n;
	s->a_min = s->a[i].n;
	while (i <= s->a_top)
	{
		s->a_max = ft_max(s->a_max, s->a[i].n);
		s->a_min = ft_min(s->a_min, s->a[i].n);
		i++;
	}
}

void five_or_less(t_stacks *s)
{
	int len;
	int n1;
	int n2;

	n1 = 0;
	n2 = 0;
	len = s->stack_len;
	if (check_stack(s))
		return ;
	else if (len == 2)
		swap_a(s);
	else if (len == 3)
	{
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
				rotate_a(s ,true);
		}
	}
	else
	{
		n1 = s->a_min;
		if (len == 5)
			n2 = get_n2(s);
		while (s->a_top > 3)
		{
			if (s->a[s->a_top].n == n1)
				push_b(s);
			else if (s->a[s->a_top].n == n2 && len == 5)
				push_b(s);
			else
				rotate_a(s, true);
		}
		if (len == 5 && s->b[1].n > s->b[2].n)
			swap_b(s);
		update_amax_amin(s);
		if (s->a_max == s->a[1].n && s->a_min == s->a[3].n)
			push_a(s);
		else if (s->a_min == s->a[1].n)
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
				rotate_a(s ,true);
		}
		while (s->b_top > 0)
			push_a(s);
	}
}

void sort(t_stacks *s)
{
	if (s->stack_len <= 5)
		five_or_less(s);
	while(!check_stack(s))
	{
		if (s->a_top == 0)
			b_to_a(s);
		else
			a_to_b(s);
	}
	all_free(s);
	return ;
}
