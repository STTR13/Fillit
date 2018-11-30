/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:45:12 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:48:00 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*s;
	unsigned char	*d;

	i = 0;
	s = dst;
	d = (unsigned char*)src;
	while (i < n)
	{
		s[i] = d[i];
		i++;
	}
	return (dst);
}
