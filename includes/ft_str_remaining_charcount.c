/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_remaining_charcount.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:46:17 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 14:26:54 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_str_remaining_char_count(const char *str, int *i)
{
	size_t	j;

	j = 0;
	while (str[(*i)])
	{
		(*i)++;
		j++;
	}
	return (j);
}
