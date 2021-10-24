/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:43 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/24 15:59:21 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

#define START 0
#define ADD_A 1
#define ADD_B 2

typedef	struct	s_stack
{
	int	*list;
	int	top;
	int	next;
}				t_stack;

typedef struct	s_stacks
{
	t_stack *a;
	t_stack *b;
	t_stack *sorted;
	t_stack *tmp;
}				t_stacks;

typedef struct	s_vars
{
	// 不変
	int		minimum;
	int		phase;

	int		a_bottom;
	int		b_top_tmp;

	// 可変
	int		a_len;
	int		b_len;
	int		a_min;
	int		b_min;

	//test
	int		k;
	int		fd;
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

void	sort(t_stacks *stacks, t_vars *vars);
void	vars_init(t_stacks *stacks, t_vars *vars);
int		get_min(t_stack *stack);
int		get_rev(t_stack *stack);
void	single_stack_sort(t_stack *stack_dst, t_stack *stack_src);


// ======================================================
void	test_start(t_stacks *stacks, t_vars *vars);
void	test_sort(t_stacks *stacks, t_vars *vars, char *str);
void	print_stack(t_stacks *stacks, t_vars *vars);
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