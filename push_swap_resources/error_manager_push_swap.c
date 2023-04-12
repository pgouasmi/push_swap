/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager_push_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:10 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/12 12:26:56 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_single_int_arg(char *str)
{
	int	i;

	i = 0;
	if (ft_str_has_ws(str)))
	{
		if (ft_check_arg_quotes(str))
			return (1);
	}
	else
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i])
		{
			if (!ft_isdigit((int)str[i]))
				return (1);
		i++;
		}
	}
	return (0);
}

int	ft_check_int_error(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (ft_str_has_ws(argv[j]))

		if (ft_check_single_int_arg(argv[j]))
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

int	ft_check_arg_quotes(char *str)
{
	size_t	i;

	ft_printf("ft_check_arg_quotes\n");
	i = 0;
	str = ft_strtrim((const char *)str, " ");
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_char(char c, int d)
{
	return (c - d);
}