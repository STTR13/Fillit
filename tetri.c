/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:45:46 by staeter           #+#    #+#             */
/*   Updated: 2018/11/18 11:45:47 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetri(tetri **te)
{
	free(*te);
	*te = NULL;
}

tetri	*new_tetri(void)
{
	tetri	*dest;
	short	i;

	if (!(dest = (tetri *)malloc(sizeof(tetri))))
		return (NULL);
	dest->letter = '\0';
	i = 0;
	while (i < 16)
		dest->tab[i++] = 0;
	return (dest);
}

boolean	fill_tetri(tetri *te, char **str, char letter)
{
	unsigned short	i, j;

	te->letter = letter;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (**str == '#')
				te->tab[i] |= (1 << j);
			else if (**str == '.')
				te->tab[i] |= (0 << j);
			else
				return (0);
			(*str)++;
			j++;
		}
		if (**str != '\n')
			return (0);
		(*str)++;
		i++;
	}
	return (1);
}

tetri	*fillnew_tetri(char **str, char letter)
{
	tetri *dest;

	if (!(dest = new_tetri())
	|| !fill_tetri(dest, str, letter))
	{
		free_tetri(&dest);
		return (NULL);
	}
	return (dest);
}
