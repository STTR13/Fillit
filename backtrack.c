/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:00:16 by staeter           #+#    #+#             */
/*   Updated: 2018/11/20 19:00:19 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static short	backtrack_rec(grid *g, tetri **tetab, boolean b)
{
	if (*tetab == NULL)
		return (1);
}

/*
** return 1 if grid has been corectly filled and 0 if any error happend
*/
boolean			backtrack(grid *g)
{
	short	l, b;

	if (!grid || (l = len_tetritab(tetab)) == -1)
		return (-1);
	g->gsize = ft_sqrt(l * 4);
	while (!(b = backtrack_rec(g, tetab, 0))
		g->gsize++;
	return ((b == 1) ? 1 : 0);
}
