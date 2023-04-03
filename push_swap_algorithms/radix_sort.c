/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:37:42 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/03 18:52:55 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_radix_sort(t_list **a_head, t_list **b_head)
{
	int mask;
	int elements_count;
	t_list *temp;
	int i;
	int count;

	mask = 1;
	count = 0;

	/*verification de tous les bits d'un int 64bits*/
	while (mask)
	{
		temp = *a_head;
		elements_count = ft_lstsize(temp); //compteur de tous les elements
		i = 0;

		/*compte le nbr d'elem a envoyer dans B*/
		while (temp)
		{
			if ((temp->content & mask) == 0)
				count++;
			temp = temp->next;
		}
		/*Detecte un element concordant bitwise et le fait remonter, pour le push B
		Le compteur i permet de donner la place de temp (valeur que l'on teste)*/
		i = 0;
		temp = *a_head;
		while (temp)
		{
			/*condition voulue : si le premier element est KO bitwise mais le second OK --> PA*/
			if ((i == 0) && (temp->next != NULL) && ((temp->content & mask) == 1) && ((temp->next->content & mask) == 0))
			{
				ft_swap_a(a_head);
				temp = *a_head;
			}
			if ((temp->content & mask) == 0)
			{
				while (*a_head != temp)
				{
					if (i < (elements_count / 2))
						ft_rotate_a(a_head);
					else
						ft_reverse_rotate_a(a_head);
				}
				if (count > 1)
				{
					ft_push_b(a_head, b_head);
				}
			}
			temp = temp->next;
			i++;
		}
		temp = *b_head;
		while (temp)
		{
			ft_push_a(a_head, b_head);
			temp = *b_head;
		}
		if (ft_list_is_ordered(a_head))
				return ;

		/*On decale le bit de 1 vers la gauche, prenant la valeur 1*/
		mask = mask << 1;
	}
	return ;
}
