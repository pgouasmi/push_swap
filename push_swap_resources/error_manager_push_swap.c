/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_push_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:10 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/29 17:52:19 by pgouasmi         ###   ########.fr       */
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
