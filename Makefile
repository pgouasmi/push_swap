# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 11:02:40 by pgouasmi          #+#    #+#              #
#    Updated: 2023/04/06 12:28:31 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCSLIB = ./includes/ft_isalnum.c	\
		./includes/ft_isalpha.c		\
		./includes/ft_isascii.c		\
		./includes/ft_isdigit.c		\
		./includes/ft_isprint.c		\
		./includes/ft_itoa.c		\
		./includes/ft_strchr.c		\
		./includes/ft_strdup.c		\
		./includes/ft_strjoin.c		\
		./includes/ft_strlcat.c		\
		./includes/ft_strlcpy.c		\
		./includes/ft_strlen.c		\
		./includes/ft_strncmp.c		\
		./includes/ft_strnstr.c		\
		./includes/ft_strrchr.c		\
		./includes/ft_strtrim.c		\
		./includes/ft_substr.c		\
		./includes/ft_tolower.c		\
		./includes/ft_toupper.c		\
		./includes/ft_atoi.c		\
		./includes/ft_itoa.c		\
		./includes/ft_split.c 		\
		./includes/ft_strtrim.c		\
		./includes/ft_substr.c		\
		./includes/ft_bzero.c		\
		./includes/ft_memcpy.c		\
		./includes/ft_memmove.c		\
		./includes/ft_memset.c		\
		./includes/ft_strmapi.c		\
		./includes/ft_striteri.c	\
		./includes/ft_calloc.c		\
		./includes/ft_memcmp.c		\
		./includes/ft_memchr.c		\
		./includes/ft_putchar_fd.c	\
		./includes/ft_putstr_fd.c	\
		./includes/ft_putnbr_fd.c	\
		./includes/ft_putendl_fd.c	\
		./includes/ft_lstadd_front.c	\
		./includes/ft_lstlast.c		\
		./includes/ft_lstnew.c		\
		./includes/ft_lstsize.c		\
		./includes/ft_printf.c		\
		./includes/ft_putchar_pf.c	\
		./includes/ft_putnbr_base.c	\
		./includes/ft_putnbr_base_p.c\
		./includes/ft_putstr_pf.c	\
		./includes/ft_str_remaining_charcount.c \
		./includes/ft_str_same_char_str.c		\
		./instructions_ps/instructions_push_swap.c	\
		./instructions_ps/instructions_push_swap2.c	\
		./instructions_ps/instructions_push_swap3.c	\
		./push_swap_resources/error_manager_push_swap.c	\
		./push_swap_resources/list_creator.c			\
		./push_swap_resources/push_swap_tools.c			\
		./push_swap_resources/radix_tools.c				\
		./push_swap_resources/radix_index_tools.c		\
		./push_swap_algorithms/push_swap_algorithms.c 	\
		./push_swap_algorithms/two_elements_case.c		\
		./push_swap_algorithms/three_elements_case.c	\
		./push_swap_algorithms/radix_sort.c	\
		

OBJS = ${SRCSLIB:.c=.o}
HEADER = libft.h
CC = cc
FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER) Makefile
			ar -rcs $(NAME) $(OBJS)

%.o:	%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

ffclean:	fclean
			rm -f ./a.out

re :
	make fclean
	make