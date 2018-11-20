/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:04:47 by staeter           #+#    #+#             */
/*   Updated: 2018/11/18 14:04:48 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		moveonposx_tetri(tetri *te, int x, unsigned short gsize)
{
	unsigned short	t[16];
	int				i;

	i = gsize;
	while (--i > gsize - x)
		if (te->tab[i])
			return (0);
	i = -1;
	while (++i < x)
		t[i] = 0;
	while (++i < gsize)
		t[i] = te->tab[i - x];
	i = -1;
	while (++i < gsize)
		te->tab[i] = t[i];
	return (1);
}

static int		moveonnegx_tetri(tetri *te, int x, unsigned short gsize)
{
	unsigned short	t[16];
	int				i;

	i = -1;
	while (++i < -x)
		if (te->tab[i])
			return (0);
	i = gsize;
	while (--i >= gsize + x)
		t[i] = 0;
	while (--i > 0)
		t[i] = te->tab[i - x];
	i = -1;
	while (++i < gsize)
		te->tab[i] = t[i];
	return (1);
}

/*
** else if move_tetri returned 0, no move has been applied
** exept while simultaneous move on x and y and the y move is invalid
** the move on x is still applied
*/
int				move_tetri(tetri *te, int x, int y, unsigned short gsize)
{
	int				i, j;

	if (x >= gsize || y >= gsize || x <= -(int)(gsize) || y <= -(int)(gsize) ||
	(x > 0 && !moveonposx_tetri(te, x, gsize)) ||
	(x < 0 && !moveonnegx_tetri(te, x, gsize)))
		return (0);
	i = -1;
	if (y < 0)
		while (++i < gsize)
		{
			j = -1;
			while (++j < -y)
				if (te->tab[i] & (1 << j))
					return (0);
			te->tab[i] = te->tab[i] >>> -y;
		}
	if (y > 0)
		while (++i < gsize)
		{
			j = gsize;
			while (--j > gsize - y)
				if (te->tab[i] & (1 << j))
					return (0);
			te->tab[i] = te->tab[i] << y;
		}
	return (1);
}

int				movetopleft_tetri(tetri *te, unsigned short gsize)
{
	int x, y, i, j;

	i = 0;
	while (i < gsize && !te->tab[i])
		i++;
	x = i;
	y = gsize;
	while (i < gsize && te->tab[i])
	{
		j = 0;
		while (j < gsize && !(te->tab[i] & (1 << j)))
			j++;
		y = (j < y) ? j : y;
	}
	return (move_tetri(te, x, y, gsize));
}
