/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:44 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/07 16:02:42 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error(t_stacks *s)
{
	ft_putendl_fd("Error", 2);
	all_free(s);
	exit(1);
}

void all_free(t_stacks *s)
{
	if (s == NULL)
		return ;
	if (s->a)
		free(s->a);
	if (s->b)
		free(s->b);
}
