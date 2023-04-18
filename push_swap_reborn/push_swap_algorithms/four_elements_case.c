/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_elements_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:52:56 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/17 16:06:16 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_four_elements_sort(t_list **a_head, t_list **b_head)
{
	int push;

	push = 0;
	while (!push)
	{
		if ((*a_head)->index == 1)
		{
			ft_push_b(a_head, b_head);
			push++;
		}
		ft_rotate_a(a_head);
	}
	ft_lst_three_elements_sort(a_head);
	ft_push_a(a_head, b_head);
	ft_print_list_values(*a_head);
}