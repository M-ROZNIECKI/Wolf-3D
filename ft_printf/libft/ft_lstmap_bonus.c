/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*newlst;
	t_list	*start;
	t_list	*prev;

	start = NULL;
	prev = NULL;
	while (lst && f)
	{
		if (!(newlst = malloc(sizeof(t_list))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		if (prev)
			prev->next = newlst;
		prev = newlst;
		newlst->content = f(lst->content);
		lst = lst->next;
		if (start == NULL)
			start = newlst;
		newlst->next = NULL;
	}
	return (start);
}
