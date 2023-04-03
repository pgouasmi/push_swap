/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:37:42 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/03 12:15:29 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_radix_sort(t_list **a_head, t_list **b_head)
{
	int mask;
	int elements_count;
	t_list *temp;
	int i;

	mask = 1;
	temp = *a_head;
	while (mask)
	{
		temp = *a_head;
		elements_count = ft_lstsize(temp);
		i = 1;
		while (temp)
		{
			if ((temp->content & mask) == 0)
			{
				while (*a_head != temp)
				{
					if (i < elements_count / 2)
						ft_rotate_a(a_head);
					else
						ft_reverse_rotate_a(a_head);
				}
				ft_push_b(a_head, b_head);
			}
			temp = temp->next;
			i++;
		}
		temp = *b_head;
		while (temp)
		{
			ft_reverse_rotate_b(b_head);
			ft_push_a(a_head, b_head);
			temp = *b_head;
		}
		mask = mask << 1;
	}
	return ;
}
