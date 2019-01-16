/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:23:46 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:54:50 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_boolean			isvalidxmove(t_tetri *te, int x, unsigned short gsize)
{
	int				i;

	if (x > 0)
	{
		if (x >= gsize)
			return (0);
		i = gsize;
		while (--i >= gsize - x)
			if (te->tab[i])
				return (0);
	}
	else if (x < 0)
	{
		if (x <= -(int)(gsize))
			return (0);
		x *= -1;
		i = -1;
		while (++i < x)
			if (te->tab[i])
				return (0);
	}
	return (1);
}

static t_boolean	isvalidymove_sub(t_tetri *te, int y,
					unsigned short gsize, int i)
{
	int		j;

	while (i < gsize && te->tab[i])
	{
		j = -1;
		while (++j < y)
			if (te->tab[i] & (1 << j))
				return (0);
		i++;
	}
	return (1);
}

t_boolean			isvalidymove(t_tetri *te, int y,
					unsigned short gsize, int i)
{
	int				j;

	if (y > 0)
	{
		if (y >= gsize)
			return (0);
		while (i < gsize && te->tab[i])
		{
			j = gsize;
			while (--j >= gsize - y)
				if (te->tab[i] & (1 << j))
					return (0);
			i++;
		}
	}
	else if (y < 0)
	{
		if (y <= -(int)(gsize))
			return (0);
		if (isvalidymove_sub(te, y, gsize, i) == 0)
			return (0);
		y *= -1;
	}
	return (1);
}

void				movetopleft_tetri(t_tetri *te, unsigned short gsize)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	while (i < gsize && !te->tab[i])
		i++;
	x = i;
	y = gsize;
	while (i < gsize && te->tab[i] && y)
	{
		j = 0;
		while (j < gsize && !(te->tab[i] & (1 << j)))
			j++;
		y = (j < y) ? j : y;
		i++;
	}
	move_tetri(te, -x, -y, gsize);
}

t_boolean			movenextline_tetri(t_tetri *te, unsigned short gsize)
{
	int	y;
	int	i;
	int	j;

	i = 0;
	while (i < gsize && !te->tab[i])
		i++;
	y = gsize;
	while (i < gsize && te->tab[i] && y)
	{
		j = 0;
		while (j < gsize && !(te->tab[i] & (1 << j)))
			j++;
		y = (j < y) ? j : y;
		i++;
	}
	return (move_tetri(te, 1, -y, gsize));
}
