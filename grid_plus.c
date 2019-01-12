/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:38:39 by nraziano          #+#    #+#             */
/*   Updated: 2019/01/12 13:38:42 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_boolean	incrtetri_grid_sub(t_grid *g, t_tetri *te)
{
	rmtetri_grid(g, te);
	if (!move_tetri(te, 0, 1, g->gsize) && !movenextline_tetri(te, g->gsize))
		return (0);
	te->ising = insertetri_grid(g, te);
	if (!te->ising || !isvalidgap(g))
		return (incrtetri_grid_sub(g, te));
	return (1);
}

t_boolean			incrtetri_grid(t_grid *g, t_tetri *te)
{
	if (!te->ising && (te->ising = insertetri_grid(g, te)))
		return (1);
	return (incrtetri_grid_sub(g, te));
}
