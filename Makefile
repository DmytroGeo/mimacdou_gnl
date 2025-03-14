# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgeorgiy <dgeorgiy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 17:59:39 by dgeorgiy          #+#    #+#              #
#    Updated: 2025/03/14 17:03:12 by dgeorgiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
CC = cc
FLAGS = -Wall -Wextra -Werror -g
SOURCES = gnl.c \
			gnl_utils.c \
			test.c

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

clean: 
		@rm -f $(OBJECTS)

fclean: clean
		@rm -f $(NAME)

re: fclean all

val: all
		valgrind ./$(NAME)

.PHONY: all clean fclean re
