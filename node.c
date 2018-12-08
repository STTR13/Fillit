/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:34:43 by staeter           #+#    #+#             */
/*   Updated: 2018/11/20 16:34:44 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_node(node **n)
{
	node *t;

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

node	*new_node(void)
{
	node *dest;

	if (!(dest = (node *)malloc(sizeof(node))))
		return (NULL);
	dest->next = NULL;
	dest->te = NULL;
	return (dest);
}

boolean	add_node(node **n, tetri *te)
{
	node *dest, *t;

	if (!te || !(dest = (node *)malloc(sizeof(node))))
		return (0);
	dest->next = NULL;
	dest->te = te;
	if (!*n)
		*n = dest;
	else
	{
		t = *n;
		while (!t->next)
			t = t->next;
		t->next = dest;
	}
	return (1);
}

void	rm_node(node **n)
{
	node *t;

	if (!*n)
	{
		t = (*n)->next;
		free(*n);
		*n = t;
	}
}
