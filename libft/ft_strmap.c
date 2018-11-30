/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:01:40 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 17:07:19 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
			scp[i] = f(s[i]);
			i++;
		}
		scp[i] = '\0';
		return (scp);
	}
	return (0);
}
