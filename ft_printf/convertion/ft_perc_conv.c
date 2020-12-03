/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_perc_conv(t_printf *wip)
{
	char *res;

	wip->flags = wip->flags & ~SPACE;
	wip->flags = wip->flags & ~PLUS;
	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = '%';
	res[1] = '\0';
	if ((wip->flags & POINT) != 0)
		wip->flags = wip->flags & ~ZERO;
	if (wip->size_champ < 2)
		return (res);
	return (ft_size_champ(res, wip, 1));
}
