/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:47 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/24 15:59:15 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av);
void	check_argv(int ac, char **av);
void	init(int ac, char **av);
void	single_stack_sort(t_stack *stack_dst, t_stack *stack_src);

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_putendl_fd("Error", 2);
	else
		check_argv(ac, av);

	return (0);
}

void	check_argv(int ac, char **av)
{
	int			i;
	int			isnum;

	printf("ac = %d\n", ac);
	i = 1;
	while (av[i])
	{
		isnum = ft_isnum(av[i]);
		if (!isnum)
		{
			ft_putendl_fd("Error", 2);
			exit(0);
		}
		i++;
	}
	init(ac, av);
}

void	init(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		stack_sorted;
	t_stack		stack_tmp;
	stack_a.list = (int *)malloc(sizeof(int *) * (ac - 1));
	stack_b.list = (int *)malloc(sizeof(int *) * (ac - 1));
	stack_sorted.list = (int *)malloc(sizeof(int *) * (ac - 1));
	stack_tmp.list = (int *)malloc(sizeof(int *) * (ac - 1));
	if (stack_a.list == NULL || stack_b.list == NULL || stack_sorted.list == NULL)
	{
		ft_putendl_fd("malloc_error", 2);
		exit(0);
	}

	int			stack_i;
	stack_i = ac - 1;
	int			av_i;
	av_i = 1;

	t_vars 		vars;
	int tmp;
	vars.k = 1; //test---------
	while (av[av_i])
	{
		tmp = ft_atoi(av[av_i]);
		stack_a.list[stack_i] = tmp;
		stack_i -= 1;
		av_i += 1;
	}
	vars.a_bottom = tmp;
	stack_a.top = ac - 1;
	stack_b.top = 0;
	stack_sorted.top = ac - 1;
	stack_sorted.next = ac - 1;
	stack_tmp.top = 0;

	t_stacks stacks;
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	stacks.sorted = &stack_sorted;
	vars.minimum = get_min(stacks.a);
	single_stack_sort(stacks.sorted, stacks.a);
	sort(&stacks, &vars);
}

void	single_stack_sort(t_stack *stack_dst, t_stack *stack_src)
{
	int		i;
	int		j;
	int		tmp;

	i = 1;
	while (i <= stack_src->top)
	{
		j = i;
		tmp = stack_src->list[i];
		while (j > 0)
		{
			if (i == 1)
			{
				stack_dst->list[i] = tmp;
				break;
			}
			else if (stack_dst->list[j - 1] > tmp)
			{
				stack_dst->list[j] = tmp;
				break;
			}
			else if (stack_dst->list[j - 1] < tmp)
			{
				while (j > 1)
				{
					if (stack_dst->list[j - 1] > tmp)
					{
						stack_dst->list[j] = tmp;
						break;
					}
					stack_dst->list[j] = stack_dst->list[j - 1];
					j--;
				}
				if (j == 1)
					stack_dst->list[j] = tmp;
				break ;
			}
			j--;
		}
		i++;
	}
	stack_dst->top = i - 1;
}
