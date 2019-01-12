/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetritab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:56:12 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 14:05:11 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_node			*quit(t_node *dest)
{
	free_node(&dest);
	return (NULL);
}

t_node				*get_tetrilist(const char *str)
{
	t_node				*dest, *t;
	char				c, cmp;
	t_tetri				*te;

	if (!str && ft_strlen(str) % 21 != 20)
		return (NULL);
	cmp = 'A' + (ft_strlen(str) / 21);
	dest = NULL;
	t = NULL;
	c = 'A';
	while ((te = getvalid_tetri((char **)(&str), c)))
	{
		if (!add_node(&t, te))
			return (quit(dest));
		if (!dest)
			dest = t;
		if (t->next)
			t = t->next;
		if (*str == '\n')
			str++;
		else if (*str == '\0' && c == cmp)
			return (dest);
		else
			return (quit(dest));
		c++;
	}
	return (quit(dest));
}

short				len_tetrilist(const t_node *n)
{
	short i;

	if (!n)
		return (-1);
	i = 0;
	while (n)
	{
		n = n->next;
		i++;
	}
	return (i);
}
