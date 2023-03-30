/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:23:00 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 16:28:08 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_swap_algorithms(t_list **a_head, t_list **b_head, int argc)
{
	*b_head = *b_head;
	
	if (argc == 0 || argc == 1)
		return ;
	if (argc == 2)
		ft_two_elements(a_head);
	// else if (argc == 3)
	// 	ft_three_elements(a_head, b_head);
	// else if (argc == 4)
	// 	ft_four_elements(a_head, b_head);		
	// else
	// 	ft_radix(a_head, b_head);
	return ;
}