/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:38:05 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:43:02 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_moreplace(const char *str, size_t i)
{
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r') ||
			(str[i] == '\f') || (str[i] == '\v') || (str[i] == ' '))
		i++;
	if (str[i] == '+')
	{
		i++;
		if (str[i] == '-')
			return (0);
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	size_t			i;
	long			tp;
	long			end;
	long			overflow;

	tp = 1;
	i = 0;
	end = 0;
	i = ft_moreplace(str, i);
	if (str[i] == '-')
	{
		tp = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		overflow = end;
		end = end * 10 + ((str[i] - 48) * tp);
		i++;
		if (overflow && ((end ^ overflow) < 0))
			return ((tp == -1) ? 0 : -1);
	}
	return (end);
}
