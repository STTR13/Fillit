/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:28:51 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:56:26 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		j;
	char	*tp;

	i = 0;
	j = ft_strlen(s);
	tp = (char*)s;
	while (s[i] != '\0')
	{
		if (tp[j - 1] == '\0' && (char)c == '\0')
			return ((char*)s + j - 1);
		if (tp[j] == (char)c)
			return ((char*)s + j);
		i++;
		j--;
	}
	if (tp[0] == (char)c)
		return ((char*)s);
	return (0);
}
