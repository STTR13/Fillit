/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:58:55 by staeter           #+#    #+#             */
/*   Updated: 2018/11/17 16:58:57 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int	linkcount(int i, int j, const tetri *te)
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

int					isvalid_tetri(const tetri *te, unsigned short gsize)
{
	int				i, j;
	unsigned int	bitcounter, linkcounter;

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

tetri				*getvalid_tetri(char **str, char letter)
{
	tetri	*dest;

	if (!(dest = fillnew_tetri(str, letter))
	|| !isvalid_tetri(dest, 4)
	|| !movetopleft_tetri(dest, 4))
	{
		free_tetri(&dest);
		return (NULL);
	}
	return (dest);
}

static tetri		*quit(tetri	*dest)
{
	tetri	*run;

	run = dest;
	while (run)
	{
		free_tetri(&run);
		run++;
	}
	free(dest);
	return (NULL);
}

tetri				*get_tetritab(const char *str)
{
	tetri	*dest, *run;
	int		i, lim;

	lim = ft_strlen(str) / 21;
	if (ft_strlen(str) % 21 != 1 ||
	!(dest = (tetri *)malloc(sizeof(tetri) * (lim + 1))))
		return (NULL);
	run = dest;
	i = 0;
	while (i < lim && (run = getvalid_tetri((char **)(&str), 'A' + i)))
	{
		i++;
		if (i != lim)
		{
			if (*str != '\n')
				return (quit(dest));
			str++;
		}
	}
	if (i != lim || *str == '\0')
		return (quit(dest));
	return (dest);
}
