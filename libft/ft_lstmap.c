/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraziano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:07:32 by nraziano          #+#    #+#             */
/*   Updated: 2018/10/23 13:10:40 by nraziano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*list;
	t_list	*one;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!list)
		{
			list = tmp;
			one = list;
			list->next = NULL;
		}
		else
		{
			list->next = tmp;
			tmp->next = NULL;
			list = list->next;
		}
		lst = lst->next;
	}
	return (one);
}
