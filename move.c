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

#include "main.h"

static void		moveonx_tetri(tetri *te, int x, unsigned short gsize)
{
	unsigned short	t[16];
	int				i;

	if (x > 0)
	{
		i = -1;
		while (++i < x)
			t[i] = 0;
		while (++i < gsize)
			t[i] = te->tab[i - x];
		i = -1;
		while (++i < gsize)
			te->tab[i] = t[i];
	}
	else if (x < 0)
	{
		i = gsize;
		while (--i >= gsize + x)
			t[i] = 0;
		while (--i > 0)
			t[i] = te->tab[i - x];
		i = -1;
		while (++i < gsize)
			te->tab[i] = t[i];
	}
}

int				move_tetri(tetri *te, int x, int y, unsigned short gsize)
{
	int				i;

	moveonx_tetri(te, x, gsize);
	if (y > 0)
	{
		i = -1;
		while (++i < gsize)
			t[i] >>> y;
	}
	if (y < 0)
	{
		i = -1;
		while (++i < gsize)
			t[i] << -y;
	}
	return (isvalid_tetri(te, gsize));
}

int				movetopleft_tetri(tetri *te, unsigned short gsize)
{
	int x, y, i, j;

	i = 0;
	while (i < gsize && !te->tab[i])
		i++;
	x = i;
	y = gsize;
	while (i < gsize && !te->tab[i])
	{
		j = 0;
		while (j < gsize && !(te->tab[i] & (1 << j)))
			j++;
		y = (j < y) ? j : y;
	}
	return (move_tetri(te, x, y, gsize));
}
