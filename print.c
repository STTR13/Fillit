/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:50:22 by staeter           #+#    #+#             */
/*   Updated: 2018/11/25 16:50:24 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		insertetri_strgrid(char *sg, tetri *te, unsigned short gsize)
{
	short i, j;

	i = 0;
	while (i < gsize)
	{
		j = 0;
		while (j < gsize)
		{
			if (te->tab[i] & (1 << j))
				sg[j + ((gsize + 1) * i)] = te->letter;
			j++;
		}
		i++;
	}
}

boolean			print_grid(const grid *g)
{
	char	*dest;
	node	*run;
	int		i, len;

	len = (g->gsize + 1) * g->gsize;
	if (!(dest = ft_strnew(len)))
		return (0);
	i = 1;
	while (i <= len)
	{
		if (i && !(i % (g->gsize + 1)))
			dest[i - 1] = '\n';
		else
			dest[i - 1] = '.';
		i++;
	}
	run = g->incr;
	while (run)
	{
		insertetri_strgrid(dest, run->te, g->gsize);
		run = run ->next;
	}
	ft_putstr(dest);
	free(dest);
	return (1);
}

void			print_tetri(const tetri *te)
{
	short i, j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (te->tab[i] & (1 << j))
				ft_putchar(te->letter);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void			print_tetriing(const tetri *te, unsigned short gsize)
{
	short i, j;

	if (gsize <= 16)
	{
		i = 0;
		while (i < gsize)
		{
			j = 0;
			while (j < gsize)
			{
				if (te->tab[i] & (1 << j))
					ft_putchar(te->letter);
				else
					ft_putchar('.');
				j++;
			}
			i++;
			ft_putchar('\n');
		}
	}
}

void			print_tetrilist(const node *n, unsigned short gsize)
{
	if (n)
	{
		print_tetriing(n->te, gsize);
		ft_putchar('\n');
		print_tetrilist(n->next, gsize);
	}
}
