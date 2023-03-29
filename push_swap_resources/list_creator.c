/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:43:06 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/29 17:51:02 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_node(t_list **a_head, int value)
{
	t_list	*new;
	t_list	*temp;

	temp = *a_head;
	new = malloc(sizeof(*new));
	if (!new)
		return (ft_free_list(a_head), 1);
	new->content = value;
	new->next = NULL;
	if (!*a_head)
		*a_head = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (0);
}

int	argv_into_list(int argc, char **argv, t_list **a_head)
{
	int	*tab;
	int	i;
	int	j;

	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (1);
	j = 1;
	i = 0;
	while (j < argc)
	{
		tab[i] = ft_atoi(argv[j]);
		if (tab[i] == 0 && argv[j][0] != 0)
			return (1);
		if (new_node(a_head, tab[i]))
			return (ft_printf("Malloc error\n"), 1);
		i++;
		j++;
	}
	return (0);
}
