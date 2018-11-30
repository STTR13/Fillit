/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:06:51 by nraziano          #+#    #+#             */
/*   Updated: 2018/11/05 15:15:59 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	i;
	unsigned int	j;

	if (s1 && s2)
	{
		j = 0;
		i = ft_strlen(s1);
		if (!(s = (char*)malloc(sizeof(char) * (i + ft_strlen(s2) + 1))))
			return (0);
		while (s1[j])
		{
			s[j] = s1[j];
			j++;
		}
		j = 0;
		while (s2[j])
		{
			s[i + j] = s2[j];
			j++;
		}
		s[i + j] = '\0';
		return (s);
	}
	return (0);
}
