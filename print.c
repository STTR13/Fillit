/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:50:22 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:57:59 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		insertetri_strgrid(char *sg, t_tetri *te, unsigned short gsize)
{
	short	i;
	short	j;

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

t_boolean			print_grid(const t_grid *g)
{
	char	*dest;
	t_node	*run;
	int		inc[2];

	inc[1] = (g->gsize + 1) * g->gsize;
	if (!(dest = ft_strnew(inc[1])))
		return (0);
	inc[0] = 1;
	while (inc[0] <= inc[1])
	{
		if (inc[0] && !(inc[0] % (g->gsize + 1)))
			dest[inc[0] - 1] = '\n';
		else
			dest[inc[0] - 1] = '.';
		inc[0]++;
	}
	run = g->incr;
	while (run)
	{
		insertetri_strgrid(dest, run->te, g->gsize);
		run = run->next;
	}
	ft_putstr(dest);
	free(dest);
	return (1);
}

void			print_tetri(const t_tetri *te)
{
	short	i;
	short	j;

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

void			print_tetriing(const t_tetri *te, unsigned short gsize)
{
	short	i;
	short	j;

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

void			print_tetrilist(const t_node *n, unsigned short gsize)
{
	if (n)
	{
		print_tetriing(n->te, gsize);
		ft_putchar('\n');
		print_tetrilist(n->next, gsize);
	}
}
