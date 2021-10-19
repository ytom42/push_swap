/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:43 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/19 09:27:27 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BOTTOM 1

typedef	struct	s_stack
{
	int	*list;
	int	top;
}				t_stack;

typedef struct	s_stacks
{
	t_stack *a;
	t_stack *b;
}				t_stacks;

typedef struct	s_vars
{
	int		min_a;
	int		min_b;
	int		rev_a;
	int		rev_b;
	int		r;
	int		rr;
}				t_vars;

void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	swap_a_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_a_b(t_stacks *stacks);
void	rev_rotate_a(t_stacks *stacks);
void	rev_rotate_b(t_stacks *stacks);
void	rev_rotate_a_b(t_stacks *stacks);

void	sort(t_stack *stack_a, t_stack *stack_b);

// ======================================================
void	test_sort(t_stacks *stacks, char *str, int fd);
void	print_stack(t_stacks *stacks);
void	print_vars(t_stacks *stacks, t_vars *vars);
// ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG; cat log.txt|./checker_Mac $ARG
// ======================================================
#endif

#include <stdio.h>
#include <fcntl.h>

// - write
// - read
// - malloc
// - free
// - exit