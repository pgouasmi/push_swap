/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_creator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:43:06 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/04/07 18:10:42 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_node(t_list **a_head, int value)
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

int	ft_argv_into_list(int argc, char **argv, t_list **a_head, size_t *arg_count)
{
	int	*tab;
	int	i;
	int	j;

	*arg_count = ft_count_args_quote(argc, argv);
	ft_printf("arg count debut de argv into list : %d\n", *arg_count);
	tab = malloc(sizeof(int) * (*arg_count));
	if (!tab)
		return (ft_printf("Malloc error\n"), 1);
	j = 1;
	i = 0;
	while (j < argc)
	{
		if (!ft_strchr((const char *)argv[j], ' '))
		{
			tab[i] = ft_atoi(argv[j]);
			if (tab[i] == 0 && !ft_str_same_char_str((ft_strtrim
						((const char *)argv[j], "+-")), '0'))
				return (ft_free_list(a_head), 1);
			i++;
		}
		else
		{
			if (ft_arg_quote_case(argv[j], &tab, &i))
				return (ft_free_list(a_head), 1);
		}
		j++;
	}
	*arg_count = ft_count_args_quote(argc, argv);
	ft_printf("arg count avant int tab to list : %d\n", *arg_count);
	ft_print_tab_values(tab, *arg_count);
	if (ft_send_int_array_to_list(arg_count, tab, a_head))
			return (1);
	return (0);
}

int	ft_send_int_array_to_list(size_t *arg_count, int *tab, t_list **a_head)
{
	size_t	i;

	i = 0;
	ft_printf("arg_count = %d\n", *arg_count);
	ft_print_tab_values(tab, *arg_count);
	while (i < (*arg_count))
	{
		ft_printf("tab[%d] = %d", i, tab[i]);
		if (ft_new_node(a_head, tab[i]))
				return (ft_printf("Malloc error\n"),  ft_free_list(a_head), 1);
		i++;
	}
	return (0);
}

int	ft_arg_quote_case(char *str, int **tab, int *i)
{
	size_t	j;
	size_t	int_count;
	char	**split;

	str = ft_strtrim((const char *)str, " ");
	split = ft_split((const char *)str, ' ');
	int_count = ft_str_count_char(str, ' ') + 1;
	if (!int_count)
		return (1);
	j = 0;
	while (j < int_count)
	{
		*tab[(*i)] = ft_atoi(split[j]);
		if (*tab[(*i)] == 0 && !ft_str_same_char_str((ft_strtrim
					((const char *)split[j], "+-")), '0'))
			return (1);
		ft_printf("tab[%d] = %d\n", *i, *tab[(*i)]);
		(*i)++;
		j++;
	}
	ft_printf("arg quote case OK\n");
	return (0);
}

size_t	ft_count_args_quote(int argc, char **argv)
{
	int		j;
	size_t	arg_count;

	j = 1;
	arg_count = 0;
	while (j < argc)
	{
		argv[j] = ft_strtrim(argv[j], "+- ");
		if(!ft_strchr((const char *)argv[j], ' '))
			arg_count++;
		else
			arg_count += (ft_str_count_char(argv[j], ' ') + 1);
		j++;
	}
	ft_printf("arg_count sortie fonction : %d\n", arg_count);
	return (arg_count);
}

size_t	ft_str_count_ws_block(char *str)
{
	size_t	i;
	size_t	count;
	size_t	is_digit;

	i = 0;
	count = 0;
	is_digit = 0;
	while (str[i])
	{
		if (ft_is_white_space(str[i]))
		{
			count++;
			while (ft_is_white_space(str[i]))
				i++;
		}
		else
		{
			if (ft_isdigit(str[i]))
				is_digit++;
			i++;
		}
	}
	if (!is_digit)
		return (0);
	return (count);
}

char **ft_split_push_swap(char *str)
{
	char **result;
	int	i;
	int j;
	int k;
	size_t	int_count;

	i = 0;
	j = 0;
	k = 0;
	int_count = ft_str_count_ws_block(str);
	result = malloc(sizeof(char*) * int_count);
	while (j < int_count)
	{
		result[j] = malloc(sizeof(char) * (ft_digit_count(str, &i)) + 1);
		while (ft_isdigit(str[i]))
		{
			result[j][k] = str[i];
			k++;
			i++;
		}
		j++;
		k = 0;
	}
	return (result);
}

int	ft_is_white_space(int c)
{
	if (c >= 9 && c <= 13 || c == 32)
		return (1);
	return (0);
}

int ft_digit_count(char *str, int *i)
{
	int count;
	int	j;

	count = 0;
	while (str[(*i)])
	{
		while (ft_is_white_space(str[(*i)]))
			(*i)++;
		j = *i;
		while (ft_isdigit(str[(j)]))
		{
			count++;
			j++;
		}
	}
	return (count);
}

int	ft_str_has_ws(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ft_is_white_space(str[i])
			return (1);
		i++;
	}
	return (0);
}
