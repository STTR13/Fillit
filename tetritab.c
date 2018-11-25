/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetritab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:56:12 by staeter           #+#    #+#             */
/*   Updated: 2018/11/25 14:56:13 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static tetri		**quit(tetri **dest)
{
	unsigned short i;

	while (dest[i])
	{
		free_tetri(&(dest[i]));
		i++;
	}
	free(dest);
	return (NULL);
}

tetri				**get_tetritab(const char *str)
{
	tetri				**dest;
	unsigned short		i, lim;

	lim = (ft_strlen(str) + 1) / 21;
	if (ft_strlen(str) % 21 != 20 ||
	!(dest = (tetri **)malloc(sizeof(tetri *) * (lim + 1))))
		return (NULL);
	i = 0;
	while (i < lim && (dest[i] = getvalid_tetri((char **)(&str), 'A' + i)))
	{
		i++;
		if (i != lim)
		{
			if (*str != '\n')
				return (quit(dest));
			str++;
		}
	}
	dest[i] = NULL;
	if (i != lim || *str == '\0')
		return (quit(dest));
	return (dest);
}

short				len_tetritab(const tetri **tetab)
{
	short i;

	if (!tetab)
		return (-1);
	i = 0;
	while (tetab[i])
		i++;
	return (i);
}

boolean				movetopleft_tetritab(tetri **tetab, unsigned short gsize)
{
	short		i;
	boolean		b;

	i = 0;
	b = 1;
	while (tetab[i] && (b = movetopleft_tetri(tetab[i], gsize)))
		i++;
	return (b);
}
