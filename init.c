/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:09:17 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 16:11:33 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(int argc, char **argv, t_stacks *s)
{
	s->stack_len = argc - 1;
	s->a_top = s->stack_len; // 配列[0]は使わない
	s->b_top = 0;
	memory_allocate(s);
	put_argument_on_stack(s, argv);
}

void	memory_allocate(t_stacks *s)
{
	s->a = (t_element *)malloc(sizeof(t_element) * (s->stack_len + 1));
	s->b = (t_element *)malloc(sizeof(t_element) * (s->stack_len + 1));
	if (s->a == NULL || s->b == NULL)
		error(s);
}

void	put_argument_on_stack(t_stacks *s, char **argv)
{
	int		i;
	int		j;
	int		tmp;

	i = 1;
	j = s->stack_len;
	s->a_max = ft_atoi(argv[i]);
	s->a_min = ft_atoi(argv[i]);
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		s->a[j].n = tmp;
		if (s->a_max < tmp)
			s->a_max = tmp;
		if (s->a_min > tmp)
			s->a_min = tmp;
		i += 1;
		j -= 1;
	}
}
