/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 20:08:47 by ytomiyos          #+#    #+#             */
/*   Updated: 2021/12/18 17:56:03 by ytomiyos         ###   ########.fr       */
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
	return (0);
}

bool	check_argument(int argc, char **argv)
{
	int	i;
	int j;
	int	isnum;

	if (argc == 1)
	{
		ft_putendl_fd("Error: No arguments.", 2);
		return (false);
	}
	i = 1;
	while (argv[i])
	{
		isnum = ft_isnum(argv[i]); //intmax?????
		if (!isnum)
		{
			ft_putendl_fd("Error: Invalid value.", 2);
			return (false);
		}
		j = i - 1;
		while (j > 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putendl_fd("Error: Duplicate numbers.", 2);
				return (false);
			}
			j--;
		}
		i++;
	}
	return (true);
}
