/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:47 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 18:53:02 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	s;

	if (check_argument(argc, argv))
	{
		init(argc, argv, &s);
		sort(&s);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}

bool	is_num(char **argv)
{
	int	i;
	int	isnum;

	i = 1;
	while (argv[i])
	{
		isnum = ft_isnum(argv[i]);
		if (!isnum)
			return (false);
		i++;
	}
	return (true);
}

bool	is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i - 1;
		while (j > 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (false);
			j--;
		}
		i++;
	}
	return (true);
}

bool	check_argument(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	if (!is_duplicate(argv))
		return (false);
	if (!is_num(argv))
		return (false);
	return (true);
}
