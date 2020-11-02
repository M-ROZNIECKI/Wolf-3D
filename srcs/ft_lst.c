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

void	ft_lst_clear(t_lst **lst, void (*del)(void*))
{
	t_lst	*elem;

	while (*lst && del)
	{
		elem = *lst;
		*lst = elem->next;
		del(elem->content);
		free(elem);
	}
}

void	ft_lst_add_back(t_lst **a_lst, t_lst *new)
{
	t_lst	*last;

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

void	ft_lst_add_frt(t_lst **alst, t_lst *new)
{
	if (new && *alst)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (!(*alst))
	{
		*alst = new;
		new->next = NULL;
	}
}

t_lst	*ft_lst_new(void *content)
{
	t_lst *str;

	if (!(str = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}

int		ft_check_list(t_wolf *wolf)
{
	t_lst *temp;

	temp = wolf->spr;
	while(temp)
	{
		if (wolf->map.map_x + 0.5 == temp->x && wolf->map.map_y + 0.5 == temp->y)
			return (0);
		temp = temp->next;
	}
	return (1);
}