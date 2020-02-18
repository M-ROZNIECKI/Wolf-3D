/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew_bonus.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 11:28:39 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 15:34:26 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_lst_map	*ft_lstnew(void *content)
{
	t_lst_map *str;

	if (!(str = (t_lst_map *)malloc(sizeof(t_lst_map))))
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
