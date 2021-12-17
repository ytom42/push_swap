/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:01:13 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/17 10:29:57 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void exec_a_rrr(t_stacks *s, int index)
{
	printf("START<%s>\n", __func__);
	printf("<TARGET>%d exec:%d \n", s->a[index].n, s->a[index].exec_num);
	int i;
	int rrr;
	t_element *element;

	i = 0;
	element = &s->a[index];
	rrr = ft_min(element->rra, element->rrb);
	while (i < rrr)
	{
		rev_rotate_a_b(s);
		i++;
	}
	if (element->rra > element->rrb)
	{
		i = 0;
		while (i < element->rra - element->rrb)
		{
			rev_rotate_a(s, true);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < element->rrb - element->rra)
		{
			rev_rotate_b(s, true);
			i++;
		}
	}
}

void exec_a_rr(t_stacks *s, int index)
{
	printf("START<%s>\n", __func__);
	printf("<TARGET>%d exec:%d \n", s->a[index].n, s->a[index].exec_num);
	int i;
	int rr;
	t_element *element;

	i = 0;
	element = &s->a[index];
	rr = ft_min(element->ra, element->rb);
	while (i < rr)
	{
		rotate_a_b(s);
		i++;
	}
	if (element->ra > element->rb)
	{
		i = 0;
		while (i < element->ra - element->rb)
		{
			rotate_a(s, true);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < element->rb - element->ra)
		{
			rotate_b(s, true);
			i++;
		}
	}
}

void exec_ra_rrb(t_stacks *s, int index)
{
	printf("START<%s>\n", __func__);
	printf("<TARGET>%d exec:%d \n", s->a[index].n, s->a[index].exec_num);
	int i;
	t_element *element;

	element = &s->a[index];
	i = 0;
	while (i < element->ra)
	{
		rotate_a(s, true);
		i++;
	}
	i = 0;
	while (i < element->rrb)
	{
		rev_rotate_b(s, true);
		i++;
	}
}

void exec_rra_rb(t_stacks *s, int index)
{
	printf("START<%s>\n", __func__);
	printf("<TARGET>%d exec:%d \n", s->a[index].n, s->a[index].exec_num);
	int i;
	t_element *element;

	element = &s->a[index];
	i = 0;
	while (i < element->rra)
	{
		rev_rotate_a(s, true);
		i++;
	}
	i = 0;
	while (i < element->rb)
	{
		rotate_b(s, true);
		i++;
	}
}

void exec_a(t_stacks *s)
{
	printf("START<%s>\n", __func__);
	int i;
	int rr;
	int rrr;
	int ra_rrb;
	int rra_rb;

	i = 1;
	while (i <= s->a_top)
	{
		if (s->a[i].exec_num == s->exec_len)
		{
			rr = ft_max(s->a[i].ra, s->a[i].rb);
			rrr = ft_max(s->a[i].rra, s->a[i].rrb);
			ra_rrb = s->a[i].ra + s->a[i].rrb;
			rra_rb = s->a[i].rra + s->a[i].rb;
			printf("rr:%d rrr:%d ra_rrb:%d rra_rb:%d\n", rr, rrr, ra_rrb, rra_rb);
			if (ra_rrb == s->exec_len)
				exec_ra_rrb(s, i);
			else if (rra_rb == s->exec_len)
				exec_rra_rb(s, i);
			else if (rr == s->exec_len)
				exec_a_rr(s, i);
			else if (rrr == s->exec_len)
				exec_a_rrr(s, i);
			push_b(s);
			return ;
		}
		i++;
	}
}
