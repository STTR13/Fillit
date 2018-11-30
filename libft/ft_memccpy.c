/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:09:52 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:47:29 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned int	i;

	i = 0;
	s = (unsigned char*)dst;
	d = (unsigned char*)src;
	while (i < n)
	{
		s[i] = d[i];
		if (d[i] == (unsigned char)c)
			return ((void*)&s[i + 1]);
		i++;
	}
	return (0);
}
