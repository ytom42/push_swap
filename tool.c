/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:15:14 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/16 22:49:46 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_min(int a, int b)
{
	return (a < b ? a : b);
}

int ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

bool is_sorted_a(t_stacks *s)
{
	int i;

	i = 1;
	while (i < s->a_top)
	{
		if (s->a[i].n < s->a[i + 1].n)
			return (false);
		i++;
	}
	return (true);
}

bool is_sorted_b(t_stacks *s)
{
	int i;

	i = 1;
	while (i < s->b_top)
	{
		if (s->b[i].n > s->b[i + 1].n)
			return (false);
		i++;
	}
	return (true);
}

bool check_stack(t_stacks *s)
{
	int i;

	i = 1;
	if (s->b_top == 0)
	{
		while (i < s->a_top)
		{
			if (s->a[i].n < s->a[i + 1].n)
				return (false);
			i++;
		}
		return (true);
	}
	else
		return (false);
}

int get_top_index_b(t_stacks *s)
{
	int i;
	int ret_index;

	ret_index = 1;
	i = 2;
	while (i <= s->b_top)
	{
		if (s->b[i].n > s->b[ret_index].n)
			ret_index = i;
		i++;
	}
	return (ret_index);
}
