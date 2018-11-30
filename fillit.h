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

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef char	boolean;

# include "libft/includes/libft.h"

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
	boolean			ising;
}				tetri;
/*
**		tetri.c
*/
void			free_tetri(tetri **te);
tetri			*new_tetri(void);
boolean			fill_tetri(tetri *te, char **str, char letter);
tetri			*fillnew_tetri(char **str, char letter);

/*
**		tetritab.c
*/
tetri			**get_tetritab(const char *str);
short			len_tetritab(const tetri **tetab);
boolean			movetopleft_tetritab(tetri **tetab, unsigned short gsize);

typedef struct	s_node
{
	tetri			*te;
	struct s_node	*next;
}				node;
/*
**		node.c
*/
void			free_node(node **n);
node			*new_node(void);
boolean			add_node(node **n, tetri *te);
void			rm_node(node **n);

typedef struct	s_grid
{
	unsigned short	gsize;
	node			*incr;
	unsigned short	tab[16];
}				grid;
/*
**		grid.c
*/
void			free_grid(grid **g);
grid			*new_grid(unsigned short gsize);
boolean				insertetri_grid(grid *g, tetri *te);
void			rmlastetri_grid(grid *g);
boolean			incrlastetri_grid(grid *g);

/*
**		reader.c
*/
char			*reader(int filedesc);
char			*standi_reader(void);
char			*file_reader(const char *filename);

/*
**		check.c
*/
int				isvalid_tetri(const tetri *te, unsigned short gsize);
tetri			*getvalid_tetri(char **str, char letter);

/*
**		move.c
*/
boolean			move_tetri(tetri *te, int x, int y, unsigned short gsize);
boolean			movetopleft_tetri(tetri *te, unsigned short gsize);
boolean			movenextline_tetri(tetri *te, unsigned short gsize);

/*
**		backtrack.c
*/
int				backtrack(grid *g, tetri **tetab);

/*
**		print.c
*/
boolean			print_grid(grid *g);
void			print_tetri(tetri *te);

#endif
