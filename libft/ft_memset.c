/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:28:00 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:48:49 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned int	i;

	i = 0;
	s = b;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	b = s;
	return (b);
}
