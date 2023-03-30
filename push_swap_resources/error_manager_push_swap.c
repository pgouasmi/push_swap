/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_push_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:10 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 15:18:41 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_single_int_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int_error(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (check_single_int_arg(argv[j]))
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_int_duplicate(int *tab, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < count)
	{
		while (j < count)
		{
			if (tab[i] == tab[j] && i != j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
