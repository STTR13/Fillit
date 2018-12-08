/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:48:38 by staeter           #+#    #+#             */
/*   Updated: 2018/11/18 13:48:39 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			free_grid(grid **g)
{
	if (*g)
	{
		free_node(&(*g)->incr);
		free(*g);
		*g = NULL;
	}
}

grid			*new_grid(unsigned short gsize)
{
	grid	*dest;
	short	i;

	if (!(dest = (grid *)malloc(sizeof(grid))))
		return (NULL);
	dest->gsize = gsize;
	dest->incr = NULL;
	i = 0;
	while (i < 16)
		dest->tab[i++] = 0;
	return (dest);
}

boolean			insertetri_grid(grid *g, tetri *te)
{
	unsigned short i, k;

	i = 0;
	while (i < g->gsize && !te->tab[i])
		i++;
	k = i;
	while (i < g->gsize && te->tab[i])
	{
		if (!(g->tab[i] & te->tab[i]))
			return (0);
		i++;
	}
	while (k < g->gsize && te->tab[k])
	{
		g->tab[k] += te->tab[k];
		k++;
	}
	return (1);
}

void			rmtetri_grid(grid *g, tetri *te)
{
	unsigned short i;

	if (te->ising)
	{
		i = 0;
		while (i < g->gsize && !te->tab[i])
			i++;
		while (i < g->gsize && te->tab[i])
		{
			g->tab[i] -= te->tab[i];
			i++;
		}
		te->ising = 0;
	}
}

static boolean	incrtetri_grid_sub(grid *g, tetri *te)
{
	rmtetri_grid(g, te);
	if (!move_tetri(te, 0, 1, g->gsize) && !movenextline_tetri(te, g->gsize))
		return (0);
	te->ising = insertetri_grid(g, te);
	if (!te->ising)
		return (incrtetri_grid_sub(g, te));
	return (1);
}

boolean			incrtetri_grid(grid *g, tetri *te)
{
	if (!te->ising && (te->ising = insertetri_grid(g, te)))
		return (1);
	return (incrtetri_grid_sub(g, te));
}
