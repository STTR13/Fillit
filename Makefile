# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: staeter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 18:32:35 by staeter           #+#    #+#              #
#    Updated: 2018/10/04 18:32:47 by staeter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = $(wildcard ./*.c)
INCLUDES = $(wildcard ./*.h)
OBJ = $(SRC:.c=.o)
PATH_LIB = libft/
LIBFT = $(PATH_LIB)libft.a
CC = gcc
FLAG = -Wall -Wextra -Werror

.PHONY : all clean fclean re lib

all: $(NAME)

$(NAME): lib
	@$(CC) $(FLAG) -c $(SRC) -I $(INCLUDES)
	@$(CC) $(FLAG) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(PATH_LIB)

re: fclean all

lib:
	@make re -C $(PATH_LIB)
