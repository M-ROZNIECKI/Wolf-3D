/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_lst_clear(t_lst **lst, void (*del)(void*))
{
	t_lst	*elem;

	if (del)
		while (*lst)
		{
			elem = *lst;
			*lst = elem->next;
			del(elem->content);
			free(elem);
		}
	else
		while (*lst)
		{
			elem = *lst;
			*lst = elem->next;
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
	while (temp)
	{
		if (wolf->map.map_x + 0.5 == temp->x &&\
		wolf->map.map_y + 0.5 == temp->y)
			return (0);
		temp = temp->next;
	}
	return (1);
}
