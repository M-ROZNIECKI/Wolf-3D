/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:39:21 by fenrir            #+#    #+#             */
/*   Updated: 2020/03/06 13:07:50 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_lst_clear(t_lst_map **lst, void (*del)(void*))
{
	t_lst_map	*elem;

	while (*lst && del)
	{
		elem = *lst;
		*lst = elem->next;
		del(elem->content);
		free(elem);
	}
}

void	ft_lst_add_back(t_lst_map **a_lst, t_lst_map *new)
{
	t_lst_map	*last;

	if (new && *a_lst)
	{
		last = *a_lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else if (!(*a_lst) && new)
	{
		*a_lst = new;
		new->next = NULL;
	}
}

t_lst_map	*ft_lst_new(void *content)
{
	t_lst_map *str;

	if (!(str = (t_lst_map *)malloc(sizeof(t_lst_map))))
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
