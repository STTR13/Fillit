/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:25:20 by staeter           #+#    #+#             */
/*   Updated: 2019/01/12 13:41:57 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		usage(const char *s)
{
	write(1, "Usage:\t", 7);
	ft_putstr(s);
	write(1, " req_filename\n", 14);
	return (0);
}

static	int		error(char **imp, t_grid **g)
{
	free(*imp);
	*imp = NULL;
	free_grid(g);
	write(1, "error\n", 6);
	return (1);
}

int				main(int argc, char const *argv[])
{
	char	*imp;
	t_grid	*g;
	short	a;

	if (argc != 2)
		return (usage(argv[0]));
	if (!(imp = file_reader(argv[1])) ||
		!(g = new_grid(0)) ||
		!(g->incr = get_tetrilist(imp)))
		return (error(&imp, &g));
	free(imp);
	a = len_tetrilist(g->incr) * 4;
	g->gsize = ft_sqrt(a);
	g->maxgap = ft_pow(g->gsize, 2) - a;
	backtrack(g);
	print_grid(g);
	free_grid(&g);
	return (0);
}
