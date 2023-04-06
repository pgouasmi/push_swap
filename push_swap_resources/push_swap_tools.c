/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:50:20 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/06 12:25:02 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list_values(t_list *head)
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
	t_list	*temp2;

	temp = *head;
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		free(temp);
	}
	free(head);
}

void	ft_print_tab_values(int *tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
	ft_printf("\n");
}

int	ft_lst_content_is_ordered(t_list **head)
{
	t_list	*temp;
	int		value;

	temp = (*head)->next;
	value = (*head)->content;
	while (temp)
	{
		if (value > temp->content)
			return (0);
		value = temp->content;
		temp = temp->next;
	}
	return (1);
}
