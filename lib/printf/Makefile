# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 18:57:17 by bnespoli          #+#    #+#              #
#    Updated: 2024/01/10 19:23:04 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES = ft_printf.h
FLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c \
	ft_printf_utils.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

%.o: %.c
	cc -I $(INCLUDES) $(FLAGS) -c $?
	ar rcs $(NAME) $@

$(NAME): $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:fclean all

.PHONY: all clean fclean re