/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:24:15 by nraziano          #+#    #+#             */
/*   Updated: 2018/11/05 15:24:45 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *end;

	if (!(end = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	else
		ft_strcpy(end, s1);
	return (end);
}
