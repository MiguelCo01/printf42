# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 17:12:33 by kcosta            #+#    #+#              #
#    Updated: 2022/10/25 12:42:51 by mmelo-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES_PATH = includes/
INCLUDES = libftprintf.h
SRCS_PATH = src/
SRCS = ft_printf.c \
	   ft_printf_func.c \
	   ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: $(SRCS_PATH)%.c
	$(CC) $(FLAGS) -I $(INCLUDES_PATH) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY: clean

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
