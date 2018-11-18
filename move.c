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

int		moveingrid_tetri(tetri *te, int x, int y, unsigned short size)
{
	unsigned short	t[16];
	int				i;

	if (x > 0)
	{
		i = -1;
		while (++i < x)
			t[i] = 0;
		while (++i < size)
			t[i] = te->tab[i - x];
		i = -1;
		while (++i < size)
			te->tab[i] = t[i];
	}
	else if (x < 0)
	{
		i = size;
		while (--i >= size + x)
			t[i] = 0;
		while (--i > 0)
			t[i] = te->tab[i - x];
		i = -1;
		while (++i < size)
			te->tab[i] = t[i];
	}
	if (y > 0)
	{
		i = -1;
		while (++i < size)
			t[i] >>> y;
	}
	if (y < 0)
	{
		i = -1;
		while (++i < size)
			t[i] << -y;
	}
	return (isvalidingrid_tetri(te, size));
}

int		movetopleft_tetri(tetri *te, unsigned short size)
{
	int x, y, i, j;

	i = 0;
	while (i < size && !te->tab[i])
		i++;
	x = i;
	y = size;
	while (i < size && !te->tab[i])
	{
		j = 0;
		while (j < size && !(te->tab[i] & (1 << j)))
			j++;
		y = (j < y) ? j : y;
	}
	return (moveingrid_tetri(te, x, y, size));
}
