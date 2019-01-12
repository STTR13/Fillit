/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:48:38 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:38:21 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			free_grid(t_grid **g)
{
	if (*g)
	{
		free_node(&(*g)->incr);
		free(*g);
		*g = NULL;
	}
}

t_grid			*new_grid(unsigned short gsize)
{
	t_grid	*dest;
	short	i;

	if (!(dest = (t_grid *)malloc(sizeof(t_grid))))
		return (NULL);
	dest->gsize = gsize;
	dest->incr = NULL;
	dest->maxgap = 0;
	i = 0;
	while (i < 16)
		dest->tab[i++] = 0;
	return (dest);
}

t_boolean		insertetri_grid(t_grid *g, t_tetri *te)
{
	unsigned short	i;
	unsigned short	k;

	i = 0;
	while (i < g->gsize && !te->tab[i])
		i++;
	k = i;
	while (i < g->gsize && te->tab[i])
	{
		if (g->tab[i] & te->tab[i])
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

void			rmtetri_grid(t_grid *g, t_tetri *te)
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
