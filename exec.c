/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:01:13 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/22 14:58:04 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	exec_rrr(t_stacks *s, int index)
{
	int			i;
	int			j;
	int			rrr;
	t_element	*element;

	i = 0;
	j = 0;
	element = &s->a[index];
	rrr = ft_min(element->rra, element->rrb);
	while (i++ < rrr)
		rev_rotate_a_b(s);
	if (element->rra > element->rrb)
		while (j++ < element->rra - element->rrb)
			rev_rotate_a(s, true);
	else
		while (j++ < element->rrb - element->rra)
			rev_rotate_b(s, true);
}

static	void	exec_rr(t_stacks *s, int index)
{
	int			i;
	int			j;
	int			rr;
	t_element	*element;

	i = 0;
	j = 0;
	element = &s->a[index];
	rr = ft_min(element->ra, element->rb);
	while (i++ < rr)
		rotate_a_b(s);
	if (element->ra > element->rb)
		while (j++ < element->ra - element->rb)
			rotate_a(s, true);
	else
		while (j++ < element->rb - element->ra)
			rotate_b(s, true);
}

static	void	exec_ra_rrb(t_stacks *s, int index)
{
	int			i;
	int			j;
	t_element	*element;

	i = 0;
	j = 0;
	element = &s->a[index];
	while (i++ < element->ra)
		rotate_a(s, true);
	while (j++ < element->rrb)
		rev_rotate_b(s, true);
}

static	void	exec_rra_rb(t_stacks *s, int index)
{
	int			i;
	int			j;
	t_element	*element;

	i = 0;
	j = 0;
	element = &s->a[index];
	while (i++ < element->rra)
		rev_rotate_a(s, true);
	while (j++ < element->rb)
		rotate_b(s, true);
}

void	exec(t_stacks *s)
{
	int	i;
	int	rr;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;

	i = s->exec_min_i;
	ra_rrb = s->a[i].ra + s->a[i].rrb;
	rra_rb = s->a[i].rra + s->a[i].rb;
	rr = ft_max(s->a[i].ra, s->a[i].rb);
	rrr = ft_max(s->a[i].rra, s->a[i].rrb);
	if (ra_rrb == s->exec_len)
		exec_ra_rrb(s, i);
	else if (rra_rb == s->exec_len)
		exec_rra_rb(s, i);
	else if (rr == s->exec_len)
		exec_rr(s, i);
	else if (rrr == s->exec_len)
		exec_rrr(s, i);
	push_b(s);
}
