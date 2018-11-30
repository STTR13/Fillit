/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:54:52 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/18 11:45:39 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	size_t	ft_ctint(int n)
{
	long long	i;
	long long	l;

	l = n;
	i = 0;
	if (l < 0)
	{
		l = l * -1;
		i++;
	}
	while (l >= 10)
	{
		l = l / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*s;
	long long	i;
	int			ct;
	int			j;

	j = 0;
	ct = ft_ctint(n);
	i = n;
	s = ft_strnew(ct + 1);
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		i = i * -1;
		j++;
	}
	s[ct + 1] = '\0';
	while (ct >= j)
	{
		s[ct] = (i % 10) + '0';
		i = i / 10;
		ct--;
	}
	return (s);
}
