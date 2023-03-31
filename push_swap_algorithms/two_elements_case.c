/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_elements_case.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:29:48 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/31 16:09:20 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_two_elements_sort(t_list **head)
{
	if (!ft_list_is_ordered(head))
		ft_swap_a(head);
	return ;
}
