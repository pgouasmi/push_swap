/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:37:42 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/02 17:02:09 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_radix_sort(t_list **a_head, t_list **b_head)
{
	int mask;
	int max_bit;
	int bit;
	t_list *temp;

	max_bit = sizeof(int) * 8;
	bit = 0;
	mask = 1;
	temp = *a_head;
	while (bit < max_bit)
	{
		temp = *a_head;
		while (temp)
		{
			if ((temp->content & mask) == 0)
			{
				while (*a_head != temp)
					ft_rotate_a(a_head);
				ft_push_b(a_head, b_head);
			}
			temp = temp->next;
		}
		temp = *b_head;
		while (temp)
		{
			ft_reverse_rotate_b(b_head);
			ft_push_a(a_head, b_head);
			temp = *b_head;
		}
		bit++;
		mask = mask << 1;
	}
	return ;
}
