/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_plus.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 23:57:20 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 20:45:40 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_plus(char *res, t_printf *wip)
{
	wip->flags = wip->flags & ~SPACE;
	if (res[0] != '-')
		return (ft_strjoinmod("+", res, 2));
	return (res);
}
