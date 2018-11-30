/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takeword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:01:02 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:58:48 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_takeword(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	str = ft_strsub(s, 0, i);
	if (str)
	{
		return (str);
	}
	return (NULL);
}
