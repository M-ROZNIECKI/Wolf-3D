/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 16:11:40 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 12:22:04 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
