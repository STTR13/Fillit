/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:58:55 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:35:35 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	linkcount(int i, int j, const t_tetri *te)
{
	unsigned int count;

	count = 0;
	if (i - 1 >= 0 && (te->tab[i - 1] & (1 << j)))
		count++;
	if (j - 1 >= 0 && (te->tab[i] & (1 << (j - 1))))
		count++;
	if (i + 1 < 4 && (te->tab[i + 1] & (1 << j)))
		count++;
	if (j + 1 < 4 && (te->tab[i] & (1 << (j + 1))))
		count++;
	return (count);
}

int					isvalid_tetri(const t_tetri *te, unsigned short gsize)
{
	int				i;
	int				j;
	unsigned int	bitcounter;
	unsigned int	linkcounter;

	bitcounter = 0;
	linkcounter = 0;
	i = 0;
	while (i < gsize)
	{
		j = 0;
		while (j < gsize)
		{
			if (te->tab[i] & (1 << j))
			{
				bitcounter++;
				linkcounter += linkcount(i, j, te);
			}
			j++;
		}
		i++;
	}
	if (bitcounter != 4 || (linkcounter != 6 && linkcounter != 8))
		return (0);
	return (1);
}

t_tetri				*getvalid_tetri(char **str, char letter)
{
	t_tetri	*dest;

	if (!(dest = fillnew_tetri(str, letter))
	|| !isvalid_tetri(dest, 4))
	{
		free_tetri(&dest);
		return (NULL);
	}
	movetopleft_tetri(dest, 4);
	return (dest);
}
