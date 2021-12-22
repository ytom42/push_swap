/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:36:14 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/22 14:33:14 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_stack(t_stacks *s)
{
	int	i;

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

int	get_top_index_b(t_stacks *s)
{
	int	i;
	int	ret_index;

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

void	update_amax_amin(t_stacks *s)
{
	int	i;

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

int	get_bottomindex_b(t_stacks *s, int n)
{
	int		i;
	int		ret_index;
	bool	first;

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

int	get_topindex_b(t_stacks *s, int n)
{
	int		i;
	int		ret_index;
	bool	first;

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
