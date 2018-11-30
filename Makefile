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

SRC = check.c grid.c inter.c move.c reader.c tetri.c
INCLUDES = main.h
OBJ =
LIB = libft/

all: $(NAME)

$(NAME): lib
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)


fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIB)

re: fclean all

lib:
	make re -C $(LIB)
