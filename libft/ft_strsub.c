/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:41:15 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:58:06 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*scp;
	unsigned int	i;
	unsigned int	j;

	j = start;
	i = 0;
	if (s != NULL)
	{
		if (!(scp = (char*)malloc(sizeof(char) * len + 1)))
			return (0);
		if (len == 0)
		{
			scp[0] = '\0';
			return (scp);
		}
		while (j <= len + start - 1)
		{
			scp[i] = s[j];
			j++;
			i++;
		}
		scp[i] = '\0';
		return (scp);
	}
	return (0);
}
