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

static node			*quit(node *dest)
{
	unsigned short i;

	free_node(&dest);
	return (NULL);
}

node				*get_tetrilist(const char *str)
{
	node				*dest, *t;
	boolean				b;

	if (ft_strlen(str) % 21 != 20)
		return (NULL);
	dest = NULL:
	i = 0;
	while ((b = add_node(&t, getvalid_tetri((char **)(&str), 'A' + i))))
	{
		if (*str == '\n')
			str++;
		else if (*str == '\0')
			break ;
		else
			return (quit(dest));
		if (!dest)
			dest = t;
		if (t->next)
			t = t->next;
	}
	if (!b || *str == '\0' || b)
		return (quit(dest));
	return (dest);
}

short				len_tetrilist(const node *n)
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

boolean				movetopleft_tetrilist(node *n, unsigned short gsize)
{
	boolean		b;

	b = 1;
	while (n && (b = movetopleft_tetri(n->te, gsize)))
		n = n->next;
	return (b);
}
