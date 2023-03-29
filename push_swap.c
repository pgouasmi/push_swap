/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:02:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/29 17:50:43 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
