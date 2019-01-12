/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:04:47 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:47:29 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		moveonposx_tetri(t_tetri *te, int x, unsigned short gsize)
{
	unsigned short	t[16];
	int				i;

	i = -1;
	while (++i < x)
		t[i] = 0;
	while (i < gsize)
	{
		t[i] = te->tab[i - x];
		i++;
	}
	i = -1;
	while (++i < gsize)
		te->tab[i] = t[i];
}

static void		moveonnegx_tetri(t_tetri *te, int x, unsigned short gsize)
{
	unsigned short	t[16];
	int				i;

	x *= -1;
	i = gsize;
	while (--i >= gsize - x)
		t[i] = 0;
	while (i >= 0)
	{
		t[i] = te->tab[i + x];
		i--;
	}
	i = -1;
	while (++i < gsize)
		te->tab[i] = t[i];
}

static void		moveony_tetri(t_tetri *te, int y, unsigned short gsize, int i)
{
	if (y > 0)
	{
		while (i < gsize && te->tab[i])
		{
			te->tab[i] = te->tab[i] << y;
			i++;
		}
	}
	else if (y < 0)
	{
		y *= -1;
		while (i < gsize && te->tab[i])
		{
			te->tab[i] = te->tab[i] >> y;
			i++;
		}
	}
}

/*
** c = 0 -> no tests applied
** c = 1 -> test x move
** c = 2 -> test y move
** c = 3 -> test all
*/

t_boolean		move_tetri(t_tetri *te, int x, int y,
				unsigned short gsize)
{
	int				i;
	short			c;

	c = 3;
	if ((c == 1 || c == 3) && !isvalidxmove(te, x, gsize))
		return (0);
	i = 0;
	if (y)
	{
		while (i < gsize && !te->tab[i])
			i++;
		if ((c == 2 || c == 3) && !isvalidymove(te, y, gsize, i))
			return (0);
		moveony_tetri(te, y, gsize, i);
	}
	if (x < 0)
		moveonnegx_tetri(te, x, gsize);
	else if (x > 0)
		moveonposx_tetri(te, x, gsize);
	return (1);
}
