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

static t_node		*quit(t_node *dest)
{
	free_node(&dest);
	return (NULL);
}

t_node				*get_tetrilist(const char *str)
{
	t_node				*var[2];
	char				c[2];
	t_tetri				*te;

	if (!str || !(ft_strlen(str) <= 545 && ft_strlen(str) % 21 == 20))
		return (NULL);
	c[1] = 'A' + (ft_strlen(str) / 21);
	var[0] = NULL;
	var[1] = NULL;
	c[0] = 'A' - 1;
	while ((te = getvalid_tetri((char **)(&str), ++c[0])))
	{
		if (!add_node(&var[1], te))
			return (quit(var[0]));
		if (!var[0])
			var[0] = var[1];
		if (var[1]->next)
			var[1] = var[1]->next;
		if (*str == '\n')
			str++;
		else
			return ((*str == '\0' && c[0] == c[1]) ? var[0] : quit(var[0]));
	}
	return (quit(var[0]));
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
