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

void	free_grid(grid **g)
{
	free_node(&(*g)->incr);
	free(*g);
	*g = NULL;
}

grid	*new_grid(unsigned short gsize)
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

int		insertetri_grid(grid *g, tetri *te)
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
	if (!add_node(&g->incr, te))
		return (-1);
	while (k < g->gsize && te->tab[k])
	{
		g->tab[k] += te->tab[k];
		k++;
	}
	return (1);
}

void	rmlastetri_grid(grid *g)
{
	unsigned short i;

	i = 0;
	while (i < g->gsize && !g->incr->te->tab[i])
		i++;
	while (i < g->gsize && g->incr->te->tab[i])
	{
		g->tab[i] -= g->incr->te->tab[i];
		i++;
	}
	rm_node(&g->incr);
}
