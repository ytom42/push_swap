/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:43 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/22 14:52:46 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_element
{
	int	n;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	ra_rrb;
	int	rra_rb;
	int	exec_num;
}				t_element;

typedef struct s_stacks
{
	t_element	*a;
	int			a_top;
	int			a_max;
	int			a_min;

	t_element	*b;
	int			b_top;

	int			stack_len;
	int			exec_len;
	int			exec_min_i;
	bool		is_first;
}				t_stacks;

bool	check_argument(int argc, char **argv);
void	init(int argc, char **argv, t_stacks *s);
void	sort(t_stacks *stacks);
void	operation_init(t_stacks *s);
void	five_or_less(t_stacks *s);
void	exec(t_stacks *s);

void	push_a(t_stacks *s);
void	push_b(t_stacks *s);
void	rotate_a(t_stacks *s, bool is_print);
void	rotate_b(t_stacks *s, bool is_print);
void	rotate_a_b(t_stacks *s);
void	rev_rotate_a(t_stacks *s, bool is_print);
void	rev_rotate_b(t_stacks *s, bool is_print);
void	rev_rotate_a_b(t_stacks *stacks);
void	swap_a(t_stacks *s);
void	swap_b(t_stacks *s);
void	swap_a_b(t_stacks *s);

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);
bool	check_stack(t_stacks *s);
int		get_top_index_b(t_stacks *s);
void	update_amax_amin(t_stacks *s);
int		get_bottomindex_b(t_stacks *s, int n);
int		get_topindex_b(t_stacks *s, int n);

void	error(t_stacks *s);
void	all_free(t_stacks *s);

#endif
