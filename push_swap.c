/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:02:50 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/02 17:07:19 by pgouasmi         ###   ########.fr       */
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
	if (ft_argv_into_list(argc, argv, &a_head))
		return (ft_printf("Error\n"), 1);
	if (a_head == NULL)
		return (ft_printf("Error\n"), 1);
	ft_print_list_values(a_head);
	ft_printf("\n\n");
	ft_push_b(&a_head, &b_head);
	ft_print_list_values(a_head);
	ft_printf("\n\n");
	ft_print_list_values(b_head);
	ft_printf("\n\n");
	ft_push_swap_algorithms(&a_head, &b_head, argc - 1);
	ft_print_list_values(a_head);
	return (0);
}
