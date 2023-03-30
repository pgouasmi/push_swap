/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_elements_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:29:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 16:31:10 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_two_elements(t_list **head)
{
	if (!ft_list_is_ordered(head))
		swap_a(head);
	return ;
}
