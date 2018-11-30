/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:17:58 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:47:18 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*c;

	c = (unsigned char*)malloc(size);
	if (c == NULL)
		return (NULL);
	ft_bzero(c, size);
	return (c);
}
