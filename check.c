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

static tetri	*quit(tetri	*dest)
{
	free(dest);
	return (NULL);
}

tetri			*gettetri(const char *str)
{
	tetri	*dest;
	int		i, j, k, lim;

	lim = strlen(str) / 21;
	if (strlen(str) % 21 != 1 ||
	!(dest = (tetri *)malloc(sizeof(tetri) * (lim + 1))))
		return (NULL);
	int i = 0;
	while (i < lim)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (*str == '#')
					dest[i][j][k] = 'A' + i;
				else if (*str == '.')
					dest[i][j][k] = *str;
				else
					return (quit(dest));
				str++;
				k++;
			}
			if (*str != '\n')
				return (quit(dest));
			str++;
			j++;
		}
		if (*str != '\n')
			return (quit(dest));
		str++;
	}
	return (dest);
}

int				subisvalid(tetri *te)
{

}

int				isvalid(tetri *te)
{

}
