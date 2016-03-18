#*****************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abureau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 12:47:45 by abureau           #+#    #+#              #
#    Updated: 2016/03/14 13:54:52 by abureau          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = test_gnl

DIRSRC = ./includes/

SRC = ./get_next_line.c \
	./main.c
CC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) -o $@ $^ -I libft/includes -L libft/ -lft

%.o: %.c
	$(CC) $(CFLAGS) -I libft/includes -o $@ -c $<

fclean:
	rm -f get_next_line.o
	rm -f test_gnl
	rm -f main.o

re: fclean all


