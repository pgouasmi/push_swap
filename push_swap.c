/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:02:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/07 18:21:03 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;
	size_t	arg_count;

	a_head = NULL;
	b_head = NULL;
	arg_count = 0;
	ft_printf("ARGC = %d\n", argc);
	ft_printf("1er argument : %s\n", argv[1]);
	if (ft_check_int_error(argc, argv))
		return (ft_printf("Error\n"), 1);
	ft_printf("check int error OK\n");
	if (ft_argv_into_list(argc, argv, &a_head, &arg_count))
		return (ft_printf("Error\n"), 1);
	ft_printf("argv_into_list OK\n");
	if (a_head == NULL)
		return (ft_printf("Error\n"), 1);
	ft_print_list_values(a_head);
	ft_printf("\n\n");
	// ft_push_b(&a_head, &b_head);
	// ft_print_list_values(a_head);
	// ft_printf("\n\n");
	// ft_print_list_values(b_head);
	// ft_printf("\n\n");
	ft_push_swap_algorithms(&a_head, &b_head, arg_count);
	ft_print_list_values(a_head);
	return (0);
}
