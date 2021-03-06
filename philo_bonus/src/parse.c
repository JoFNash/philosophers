/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olga <olga@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 01:20:16 by olga              #+#    #+#             */
/*   Updated: 2022/07/04 01:20:17 by olga             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher_bonus.h"

int	ft_valid_argv(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (num[i] == ' ' || num[i] == '\t' || num[i] == '\v'
			|| num[i] == '\r' || num[i] == '\n')
		{
			i ++;
			while (!(num[i] >= '0' && num[i] <= '9'))
				i ++;
		}
		else if (num[i] >= '0' && num[i] <= '9')
			i ++;
		else if (num[i] == '+')
			i ++;
		else if (num[i] == '-')
			return (0);
		else
			return (0);
	}
	return (1);
}

int	parse(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (0);
	while (++ i < ac)
	{
		if (ft_valid_argv(av[i]) == 0)
			return (0);
	}
	return (1);
}

int	ft_prog(int argc, char *argv[])
{
	if (!parse(argc, argv))
	{
		error_message(1);
		return (1);
	}
	return (0);
}
