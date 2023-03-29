/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:02:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/29 17:10:59 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_values(t_list *a_head)
{
	t_list	*temp;

	temp = a_head;
	while (temp)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}

void	new_node(t_list **a_head, int value)
{
	t_list	*new;
	t_list	*temp;

	temp = *a_head;
	new = malloc(sizeof(*new));
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
		new_node(a_head, tab[i]);
		i++;
		j++;
	}
	return (0);
}

int	check_single_int_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit((int)str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_int_error(int argc, char **argv)
{
	int	j;

	j = 1;
	while (j < argc)
	{
		if (check_single_int_arg(argv[j]))
			return (1);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (ft_check_int_error(argc, argv))
		return (ft_printf("Error\n"), 1);
	if (argv_into_list(argc, argv, &a_head))
		return (ft_printf("Error\n"), 1);
	if (a_head == NULL)
		return (ft_printf("Error\n"), 1);
	print_values(a_head);
	ft_printf("\n\n");
	push_b(&a_head, &b_head);
	push_b(&a_head, &b_head);
	print_values(a_head);
	ft_printf("\n\n");
	print_values(b_head);
	ft_printf("\n\n");
	rotate_b(&b_head);
	print_values(a_head);
	ft_printf("\n\n");
	print_values(b_head);
	ft_printf("\n\n");
	rr (&a_head, &b_head);
	print_values(a_head);
	ft_printf("\n\n");
	print_values(b_head);
	ft_printf("\n\n");
	reverse_rotate_a (&a_head);
	print_values(a_head);
	ft_printf("\n\n");
	reverse_rotate_b (&b_head);
	print_values(b_head);
	ft_printf("\n\n");
	rrr(&a_head, &b_head);
	print_values(a_head);
	ft_printf("\n\n");
	print_values(b_head);
	ft_printf("\n\n");

	// print_values(a_head);
	// ft_printf("\n\n");
	// push_b(&a_head, &b_head);
	// ft_printf("\n\n");
	// print_values(b_head);
	// ft_printf("\n\n");
	// push_a(&a_head, &b_head);
	// ft_printf("\n\n");
	// print_values(b_head);
	// print_values(a_head);
}
