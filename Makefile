# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imontero <imontero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 19:35:16 by imontero          #+#    #+#              #
#    Updated: 2023/04/19 19:35:16 by imontero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= 	ft_printf_bonus.c \
				ft_strchr.c \
				ft_memset.c \
				ft_strlen.c \
				ft_itoa.c \
				ft_strdup.c \
				ft_printnbr.c \
				ft_printnbr_aux.c \
				ft_printnbru.c \
				ft_printnbru_aux.c \
				ft_printstr.c \
				ft_printchar.c \
				ft_printhex.c \
				ft_printpointer.c \
				ft_printhexptr.c \
				utils_left_bonus.c \
				utils_bonus.c \
				utils2_bonus.c \

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror

$(NAME): 
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS) 

all: $(NAME)

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
