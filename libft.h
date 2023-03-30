/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:09:42 by pgouasmi          #+#    #+#             */
/*   Updated: 2023/03/30 22:27:14 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size );
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_printf(const char *s, ...);
void	ft_putchar_pf(int c, size_t *char_count);
void	ft_putstr_pf(const char *s, size_t *char_count);
void	ft_putnbr_base(long long int n, const char *base, size_t *char_count);
void	ft_putnbr_base_p(size_t n, const char *base, size_t *char_count);
int		ft_str_same_char_str(const char *str, int c);
size_t	ft_str_remaining_char_count(const char *str, int *i);
int		ft_check_single_int_arg(char *str);
int		ft_check_int_error(int argc, char **argv);
int		ft_check_int_duplicate(int *tab, int argc);
int		ft_argv_into_list(int argc, char **argv, t_list **a_head);
int		ft_new_node(t_list **a_head, int value);
void	ft_print_tab_values(int *tab, int count);
void	ft_print_list_values(t_list *head);
void	ft_free_list(t_list	**head);
void	ft_swap_a(t_list **a_head);
void	ft_swap_b(t_list **b_head);
void	ft_ss(t_list **a_head, t_list **b_head);
void	ft_push_a(t_list **a_head, t_list **b_head);
void	ft_push_b(t_list **a_head, t_list **b_head);
void	ft_rotate_a(t_list **head);
void	ft_rotate_b(t_list **head);
void	ft_rr(t_list **head_a, t_list **head_b);
void	ft_reverse_rotate_a(t_list **head);
void	ft_reverse_rotate_b(t_list **head);
void	ft_rrr(t_list **head_a, t_list **head_b);
void	ft_push_swap_algorithms(t_list **a_head, t_list **b_head, int argc);
void	ft_two_elements(t_list **head);
int		ft_list_is_ordered(t_list **head);

#endif