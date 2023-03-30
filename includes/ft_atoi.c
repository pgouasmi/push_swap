/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:05:35 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 22:27:50 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_pos_neg(const char *str, int *i)
{
	if (str[(*i)] == '-')
	{
		(*i)++;
		return (0);
	}
	else if (str[(*i)] == '+')
	{
		(*i)++;
		return (1);
	}
	else if (str[(*i)] >= '0' && str[(*i)] <= '9')
		return (1);
	else
		return (2);
}

static void	ft_skipws(const char *str, int *i)
{
	while (str[(*i)] == '\t' || str[(*i)] == '\n'
		|| str[(*i)] == '\v' || str[(*i)] == '\f'
		|| str[(*i)] == '\r' || str[(*i)] == ' ')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	i = 0;
	result = 0;
	ft_skipws(str, &i);
	if ((str[i] == '+' || str[i] == '-')
		&& (ft_str_same_char_str(ft_substr(str, (unsigned int) i,
					ft_str_remaining_char_count(str, &i)), '0')))
		return (0);
	sign = check_pos_neg(str, &i);
	if (sign == 2)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (sign == 0)
		result = result * -1;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}
