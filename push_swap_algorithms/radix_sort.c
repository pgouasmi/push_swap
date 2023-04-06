/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:37:42 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/06 12:04:50 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_radix_sort(t_list **a_head, t_list **b_head)
{
	int mask;
	int elements_count;
	t_list *temp;
	int count;

	mask = 1;

	/*verification de tous les bits d'un int 64bits*/
	while (mask)
	{
		count = 0;
		temp = *a_head;
		elements_count = ft_lstsize(*a_head); //compteur de tous les elements
		ft_lst_position_initialize(a_head);
		ft_lst_index_initialize(a_head, elements_count);

		/*compte le nbr d'elem a envoyer dans B*/
		while (temp)
		{
			if ((temp->index & mask) == 0)
				count++;
			temp = temp->next;
		}
		
		/*Detecte un element concordant bitwise et le fait remonter, pour le push B
		Le compteur i permet de donner la place de temp (valeur que l'on teste)*/
		temp = *a_head;
		while (temp)
		{
			/*condition voulue : si le premier element est KO bitwise mais le second OK --> PA*/
			if (((*a_head)->index & mask) == 1)
			{
				if (((*a_head)->next->index & mask) == 0)
				{
					ft_swap_a(a_head);
					temp = *a_head;
				}
			}
			if ((temp->index & mask) == 0)
			{
				ft_lst_rotate_to_top_a(a_head, temp->position, elements_count);
				if (count > 1)
				{
					ft_push_b(a_head, b_head);
					temp = *a_head;
				}
			}
			if (!ft_lst_position_is_ordered(a_head))
				ft_lst_reorder_position(a_head);
			temp = temp->next;
		}

		/*vidage de la liste B*/

		temp = *b_head;
		while (temp)
		{
			ft_reverse_rotate_b(b_head);
			ft_push_a(a_head, b_head);
			temp = *b_head;
		}
		if (ft_lst_content_is_ordered(a_head))
				return ;

		ft_print_list_values(*a_head);
		ft_printf("\n");
		ft_print_list_index(*a_head);
		ft_printf("\n");

		/*On decale le bit de 1 vers la gauche, prenant la valeur 1*/
		mask = mask << 1;
	}
	return ;
}

// if ((temp == *a_head) && (temp->next != NULL) && ((temp->content & mask) == 1) && ((temp->next->content & mask) == 0))
