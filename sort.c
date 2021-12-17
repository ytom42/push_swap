/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:34:39 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/17 10:43:03 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void a_to_b(t_stacks *s)
{
	printf("START<%s>\n", __func__);
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

	printf("START<%s>\n", __func__);
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

void sort(t_stacks *s)
{
	fd = open("./log.txt", O_WRONLY);
	// fd = 1;
	while(!check_stack(s))
	{
		// print_stack(s); //input
		// if (is_sorted_a(s))
		if (s->a_top == 0)
			b_to_a(s);
		else
			a_to_b(s);
	}
	all_free(s);
	printf("END\n"); //test
	return ;
}
