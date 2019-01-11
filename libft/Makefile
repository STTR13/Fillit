# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nraziano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 21:28:27 by nraziano          #+#    #+#              #
#    Updated: 2018/11/04 14:57:17 by nraziano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard ./*.c)
INCLUDES = $(wildcard ./includes/*.h)
OBJ = ft_isdigit.o ft_strcat.o ft_strequ.o ft_strnequ.o ft_isprint.o \
ft_strchr.o ft_strlcat.o ft_strnstr.o ft_strmap.o ft_strmapi.o  \
ft_atoi.o ft_putchar.o ft_strclr.o ft_strlen.o ft_strstr.o \
ft_isalnum.o ft_putendl.o ft_strcmp.o ft_strncat.o ft_tolower.o \
ft_isalpha.o ft_putnbr.o ft_strcpy.o ft_strncmp.o ft_toupper.o \
ft_isascii.o ft_putstr.o ft_strdup.o ft_strncpy.o ft_bzero.o   \
ft_memset.o ft_memcpy.o ft_memccpy.o ft_memmove.o ft_memchr.o  \
ft_memcmp.o ft_memalloc.o ft_strnew.o ft_memdel.o ft_strdel.o  \
ft_striter.o ft_striteri.o ft_strsub.o ft_strjoin.o ft_strtrim.o  \
ft_strsplit.o ft_strrchr.o ft_itoa.o ft_putchar_fd.o ft_putstr_fd.o  \
ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o  \
ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_countwords.o ft_takeword.o   \
ft_nextword.o ft_realloc.o ft_sqrt.o ft_pow.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
