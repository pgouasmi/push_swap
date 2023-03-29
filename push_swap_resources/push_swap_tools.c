/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:50:20 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/29 18:33:02 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_values(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}

void	ft_free_list(t_list	**head)
{
	t_list	*temp;

	temp = *head;
	while (temp->next)
	{
		free(temp);
		temp = temp->next;
	}
}
