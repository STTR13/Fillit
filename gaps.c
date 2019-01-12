/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:14:45 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:33:59 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned short	get_gap(unsigned short t[16], short x, short y,
						unsigned short gsize)
{
	unsigned short acc;

	acc = 1;
	t[x] |= (1 << y);
	if (y + 1 < gsize && !(t[x] & (1 << (y + 1))))
		acc += get_gap(t, x, y + 1, gsize);
	if (y - 1 >= 0 && !(t[x] & (1 << (y - 1))))
		acc += get_gap(t, x, y - 1, gsize);
	if (x + 1 < gsize && !(t[x + 1] & (1 << y)))
		acc += get_gap(t, x + 1, y, gsize);
	if (x - 1 >= 0 && !(t[x - 1] & (1 << y)))
		acc += get_gap(t, x - 1, y, gsize);
	return (acc);
}

t_boolean					isvalidgap(const t_grid *g)
{
	unsigned short	t[16];
	short			i;
	short			j;
	unsigned short	gap;
	unsigned short	a;

	i = -1;
	while (++i < g->gsize)
		t[i] = g->tab[i];
	gap = 0;
	i = -1;
	while (++i < g->gsize)
	{
		j = -1;
		while (t[i] && ++j < g->gsize)
			if (!(t[i] & (1 << j)))
			{
				a = get_gap(t, i, j, g->gsize);
				gap += (a > 3) ? 0 : a;
				if (gap > g->maxgap)
					return (0);
			}
	}
	return (1);
}
