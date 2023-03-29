/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_swap2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:02:53 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/29 16:50:01 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate_a(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*head)
		return ;
	first = *head;
	second = (*head)->next;
	if (!second)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = second;
	ft_printf("ra\n");
}

void	rotate_b(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	if (!*head)
		return ;
	first = *head;
	second = (*head)->next;
	if (!second)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*head = second;
	ft_printf("rb\n");
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate_a(head_a);
	rotate_b(head_b);
}
