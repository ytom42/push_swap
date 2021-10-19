/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:47 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/10/17 13:39:06 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av);
void	check_argv(int ac, char **av);
void	init(int ac, char **av);

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
	int			stack_i;
	int			av_i;
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a.list = (int *)malloc(sizeof(int *) * (ac - 1));
	stack_b.list = (int *)malloc(sizeof(int *) * (ac - 1));
	if (stack_a.list == NULL || stack_b.list == NULL)
	{
		ft_putendl_fd("malloc_error", 2);
		exit(0);
	}
	stack_i = ac - 1;
	av_i = 1;
	while (av[av_i])
	{
		stack_a.list[stack_i] = ft_atoi(av[av_i]);
		stack_i -= 1;
		av_i += 1;
	}
	stack_a.top = ac - 1;
	stack_b.top = 0;
	sort(&stack_a, &stack_b);
}
