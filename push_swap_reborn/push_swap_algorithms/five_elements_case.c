/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements_case.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:31:19 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/17 16:04:27 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_five_elements_sort(t_list **a_head, t_list **b_head)
{
	int push;

	push = 0;
	while (push != 2)
	{
		if ((*a_head)->index == 1 || (*a_head)->index == 2)
		{
			ft_push_b(a_head, b_head);
			push++;
		}
		else
			ft_rotate_a(a_head);
	}
	ft_lst_three_elements_sort(a_head);
	if ((*b_head)->index == 2)
	{
		ft_push_a(a_head, b_head);
		ft_push_a(a_head, b_head);
	}
	else
	{
		ft_swap_b(b_head);
		ft_push_a(a_head, b_head);
		ft_push_a(a_head, b_head);
	}
	//ft_print_list_values(*a_head);
}