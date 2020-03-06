/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:39:21 by fenrir            #+#    #+#             */
/*   Updated: 2020/02/28 14:39:21 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;

	while (*lst && del)
	{
		elem = *lst;
		*lst = elem->next;
		del(elem->content);
		free(elem);
	}
}

void	ft_lstadd_back(t_lst_map **alst, t_lst_map *new)
{
	t_lst_map	*last;

	if (new && *alst)
	{
		last = *alst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else if (!(*alst) && new)
	{
		*alst = new;
		new->next = NULL;
	}
}

t_lst_map	*ft_lstnew(void *content)
{
	t_lst_map *str;

	if (!(str = (t_lst_map *)malloc(sizeof(t_lst_map))))
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
