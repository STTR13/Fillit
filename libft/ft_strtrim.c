/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:38:09 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:58:35 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

static	int		ft_ctendword(char const *s)
{
	unsigned int	j;
	unsigned int	k;

	k = 0;
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		j--;
		k++;
	}
	return (k);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	char			*scpy;

	i = 0;
	if (s)
	{
		if (s[i] == '\0')
			return ((char*)s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i++;
			if (s[i] == '\0')
			{
				scpy = ft_memalloc(1);
				return (scpy);
			}
		}
		scpy = ft_strsub(s, i, ft_strlen(s) - i - ft_ctendword(s));
		return (scpy);
	}
	return (0);
}
