/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 11:45:46 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 14:16:39 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetri(t_tetri **te)
{
	free(*te);
	*te = NULL;
}

t_tetri	*new_tetri(void)
{
	t_tetri	*dest;
	short	i;

	if (!(dest = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	dest->letter = '\0';
	dest->ising = 0;
	i = 0;
	while (i < 16)
		dest->tab[i++] = 0;
	return (dest);
}

t_boolean	fill_tetri(t_tetri *te, char **str, char letter)
{
	unsigned short	i;
	unsigned short	j;

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

t_tetri	*fillnew_tetri(char **str, char letter)
{
	t_tetri *dest;

	if (!(dest = new_tetri())
	|| !fill_tetri(dest, str, letter))
	{
		free_tetri(&dest);
		return (NULL);
	}
	return (dest);
}
