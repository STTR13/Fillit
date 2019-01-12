/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:00:51 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:31:40 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef char		t_boolean;

/*
**	0 -- > y
**	|
**	v		te->tab[x] & (1 << y) == value in (x,y)
**	x
*/
typedef struct		s_tetri
{
	char			letter;
	unsigned short	tab[16];
	t_boolean		ising;
}					t_tetri;
/*
**		tetri.c
*/
void				free_tetri(t_tetri **te);
t_tetri				*new_tetri(void);
t_boolean			fill_tetri(t_tetri *te, char **str, char letter);
t_tetri				*fillnew_tetri(char **str, char letter);

typedef struct		s_node
{
	t_tetri			*te;
	struct s_node	*next;
}					t_node;
/*
**		node.c
*/
void				free_node(t_node **n);
t_node				*new_node(void);
t_boolean			add_node(t_node **n, t_tetri *te);
void				rm_node(t_node **n);

/*
**		tetrilist.c
*/
t_node				*get_tetrilist(const char *str);
short				len_tetrilist(const t_node *n);

typedef struct		s_grid
{
	unsigned short	gsize;
	t_node			*incr;
	unsigned short	tab[16];
	unsigned short	maxgap;
}					t_grid;
/*
**		grid.c
*/
void				free_grid(t_grid **g);
t_grid				*new_grid(unsigned short gsize);
t_boolean			insertetri_grid(t_grid *g, t_tetri *te);
void				rmtetri_grid(t_grid *g, t_tetri *te);
t_boolean			incrtetri_grid(t_grid *g, t_tetri *te);

/*
**		gaps.c
*/
t_boolean			isvalidgap(const t_grid *g);

/*
**		reader.c
*/
char				*reader(int filedesc);
char				*standi_reader(void);
char				*file_reader(const char *filename);

/*
**		check.c
*/
int					isvalid_tetri(const t_tetri *te, unsigned short gsize);
t_tetri				*getvalid_tetri(char **str, char letter);

/*
**		move.c
*/
t_boolean			move_tetri(t_tetri *te, int x, int y,
					unsigned short gsize);
t_boolean			isvalidxmove(t_tetri *te, int x, unsigned short gsize);
t_boolean			isvalidymove(t_tetri *te, int y,
					unsigned short gsize, int i);
void				movetopleft_tetri(t_tetri *te, unsigned short gsize);
t_boolean			movenextline_tetri(t_tetri *te, unsigned short gsize);

/*
**		backtrack.c
*/
void				backtrack(t_grid *g);

/*
**		print.c
*/
t_boolean			print_grid(const t_grid *g);
void				print_tetri(const t_tetri *te);
void				print_tetriing(const t_tetri *te, unsigned short gsize);
void				print_tetrilist(const t_node *n, unsigned short gsize);

#endif
