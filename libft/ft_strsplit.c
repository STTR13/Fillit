/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:01:32 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:56:47 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static	void	ft_advancetab(char **s, char c)
{
	while (**s == c)
	{
		*s = *s + 1;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;

	if (s)
	{
		j = ft_countwords(s, c);
		if ((tab = (char **)malloc(sizeof(char *) * (j + 1))))
		{
			if ((str = ft_strdup(s)))
			{
				i = 0;
				while (i < j)
				{
					ft_advancetab(&str, c);
					if ((tab[i++] = ft_takeword(str, c)))
						ft_nextword(&str, c);
				}
				tab[i] = NULL;
				return (tab);
			}
		}
	}
	return (NULL);
}
