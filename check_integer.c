/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytomiyos <ytomiyos@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:08:30 by ytomiyos          #+#    #+#             */
/*   Updated: 2022/01/09 17:56:15 by ytomiyos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	bool	over_max(char *s)
{
	int		i;
	char	*max;

	i = 0;
	max = "2147483647";
	while (s[i])
	{
		if (s[i] > max[i])
			return (false);
		else if (s[i] < max[i])
			break ;
		i++;
	}
	return (true);
}

static	bool	over_min(char *s)
{
	int		i;
	char	*min;

	i = 0;
	min = "-2147483648";
	while (s[i])
	{
		if (s[i] > min[i])
			return (false);
		else if (s[i] < min[i])
			break ;
		i++;
	}
	return (true);
}

bool	check_minmax(char *s)
{
	if (s[0] == '-')
	{
		if (!over_min(s))
			return (false);
	}
	else
	{
		if (!over_max(s))
			return (false);
	}
	return (true);
}

# include <stdio.h>

bool	check_integer(char **argv)
{
	int		i;
	int		len;
	char	*s;

	i = 1;
	while (argv[i])
	{
		s = argv[i];
		len = ft_strlen(s);
		if (len > 11)
			return (false);
		else if (len < 10 || (len < 11 && s[0] == '-'))
		{
			i++;
			continue ;
		}
		else
			if (!check_minmax(s))
				return (false);
		i++;
	}
	return (true);
}
