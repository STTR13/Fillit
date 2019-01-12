/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:34:43 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:42:57 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_node(t_node **n)
{
	t_node *t;

	if (*n)
	{
		t = (*n)->next;
		free_tetri(&(*n)->te);
		free(*n);
		if (t != NULL)
		{
			*n = t;
			free_node(&t);
		}
		else
			*n = NULL;
	}
}

t_node	*new_node(void)
{
	t_node *dest;

	if (!(dest = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	dest->next = NULL;
	dest->te = NULL;
	return (dest);
}

t_boolean	add_node(t_node **n, t_tetri *te)
{
	t_node	*dest;
	t_node	*t;

	if (!te || !(dest = new_node()))
		return (0);
	dest->te = te;
	if (!*n)
		*n = dest;
	else
	{
		t = *n;
		while (t->next)
			t = t->next;
		t->next = dest;
	}
	return (1);
}

void	rm_node(t_node **n)
{
	t_node *t;

	if (!*n)
	{
		t = (*n)->next;
		free(*n);
		*n = t;
	}
}
