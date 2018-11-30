/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:55:22 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:48:39 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*sd;
	unsigned char		*sc;
	size_t				i;

	sd = (unsigned char*)dst;
	sc = (unsigned char*)src;
	i = 0;
	if (sc < sd)
	{
		while (i < len)
		{
			sd[len - 1] = sc[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			sd[i] = sc[i];
			i++;
		}
	}
	return (dst);
}
