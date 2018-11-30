/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:21:17 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:55:50 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*tab;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			tab = (char*)haystack + i;
			j = 0;
			while (haystack[i + j] == needle[j] && j + i < len)
			{
				if (needle[j + 1] == '\0')
					return (tab);
				j++;
			}
			tab = 0;
		}
		i++;
	}
	return (0);
}
