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

#include "main.h"

static unsigned int	linkcount(int i, int j, tetri *te)
{
	unsigned int count;

	count = 0;
	if (i - 1 >= 0 && (te[i - 1] & (1 << j)))
		count++;
	if (j - 1 >= 0 && (te[i] & (1 << (j - 1))))
		count++;
	if (i + 1 < 4 && (te[i + 1] & (1 << j)))
		count++;
	if (j + 1 < 4 && (te[i] & (1 << (j + 1))))
		count++;
	return (count);
}

int					isvalid_tetri(const tetri *te)
{
	int				i, j;
	unsigned int	bitcount, linkcount;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (te[i] & (1 << j))
			{
				bitcount++;
				linkcount = linkcount(i, j, te);
			}
			j++;
		}
		i++;
	}
	if (bitcount != 4 || (linkcount != 6 && linkcount != 8))
		return (0);
	return (1);
}

tetri				*getvalid_tetri(char **str, char letter)
{
	tetri	*dest;

	if (!(dest = fillnew_tetri(str, letter))
	|| !isvalid_tetri(dest))
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
	int i = 0;
	while (i<lim && (run = getvalid_tetri(&str, 'A' + i)))
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
