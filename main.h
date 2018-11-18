/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:00:51 by staeter           #+#    #+#             */
/*   Updated: 2018/11/17 17:00:53 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//# include "libft/libft.h"

/*
**	0 -- > y
**	|
**	v		te->tab[x] & (1 << y) == value in (x,y)
**	x
*/
typedef struct	s_tetri
{
	char			letter;
	unsigned short	tab[16];
}				tetri;
/*
**		tetri.c
*/
void			free_tetri(tetri **te);
tetri			*new_tetri(void);
int				fill_tetri(tetri *te, char **str, char letter);
tetri			*fillnew_tetri(char **str, char letter);

typedef struct	s_node
{
	tetri			*te;
	struct s_node	*next;
}				node;
/*
**		node.c
*/

typedef struct	s_grid
{
	unsigned short	size;
	node			*incr;
	unsigned short	tab[16];
}				grid;
/*
**		grid.c
*/

/*
**		reader.c
*/
char			*reader(int filedesc);
char			*standi_reader(void);
char			*file_reader(const char *filename);

/*
**		check.c
*/
int				isvalid_tetri(const tetri *te);
int				isvalidingrid_tetri(const tetri *te, unsigned short size);
tetri			*getvalid_tetri(char **str, char letter);
tetri			*get_tetritab(const char *str);

/*
**		move.c
*/
int				moveingrid_tetri(tetri *te, int x, int y, unsigned short size);
int				movetopleft_tetri(tetri *te, unsigned short size);

/*
**		inter.c
*/

#endif
