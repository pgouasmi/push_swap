/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:50:31 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/02/17 14:00:31 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int	ft_atoi(const char *str)
{
	long long int	result;
	int				i;
	int				sign;

	i = 0;
	result = 0;
	sign = check_pos_neg(str, &i);
	if (sign == 2)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result != ((result * 10 + (sign * (str[i] - '0'))) / 10))
			return ((int)((sign + 1) / 2 / -1));
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (sign == 0)
		result = result * -1;
	if (result > 2147483647 || result < -2147483648)
		return (0);
	return ((int)result);
}

int check_arg(char* str)
{
	 int i;

	 i = 0;
	 if (str[i] == '-')
	 	i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int main (int argc, char **argv)
{
	int j;
	int tab[argc - 1];

	j = 0;
	while (++j < argc)
	{
		if (check_arg(argv[j]))
			return (printf("Probleme sur le %deme argument\n", j), 1);
	}
	j = 0;
	while(j < argc - 1)
	{
		printf("argument no %d\n", j + 1);
		tab[j] = ft_atoi(argv[j + 1]);
		if (tab[j] == 0 && argv[j + 1][0] != '0')
			return (printf("Probleme sur le %deme argument\n", j + 1), 1);
		printf("tab[%d] = %d\n", j, tab[j]);
		j++;
	}
	return (printf("Alrighty\n"), 0);
}