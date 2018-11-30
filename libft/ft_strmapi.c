/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:24:38 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 17:08:33 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*scp;

	i = 0;
	if (s && (*f))
	{
		scp = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (scp == 0)
			return (0);
		while (s[i])
		{
			scp[i] = f(i, s[i]);
			i++;
		}
		scp[i] = '\0';
		return (scp);
	}
	return (0);
}
