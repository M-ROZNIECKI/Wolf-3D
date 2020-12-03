/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_omin_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libconv.h"

static char	*ft_select_size(t_printf *wip)
{
	char *res;

	if ((wip->flags & L_MIN) != 0)
		return (ft_lflag(wip));
	else if ((wip->flags & LL_MIN) != 0)
		return (ft_llflag(wip));
	else if ((wip->flags & H_MIN) != 0)
		return (ft_hflag(wip));
	else if ((wip->flags & HH_MIN) != 0)
		return (ft_hhflag(wip));
	else
		res = ft_itoa_base(va_arg(wip->ap, unsigned int), "01234567");
	return (res);
}

char		*ft_omin_conv(t_printf *wip)
{
	char	*res;
	int		size_data;

	wip->flags = wip->flags & ~SPACE;
	res = ft_select_size(wip);
	size_data = ft_strlen(res);
	if ((wip->flags & APOST) != 0)
		res = ft_apost(res);
	if ((wip->flags & POINT) != 0)
		size_data = ft_precision(&res, wip, size_data);
	if ((wip->flags & POINT) == POINT)
		wip->flags = wip->flags & ~ZERO;
	if (((wip->flags & (HASH + POINT)) == HASH) && (res[0] != '0'))
		res = ft_hash(res, wip, size_data);
	if ((((wip->flags & (HASH + POINT)) == HASH) && (res[0] == '0')) ||
		((wip->flags & (HASH + POINT)) == HASH + POINT))
		wip->flags = wip->flags & ~HASH;
	wip->flags = wip->flags & ~PLUS;
	size_data = ft_strlen(res);
	if (wip->size_champ <= size_data)
		return (res);
	return (ft_size_champ(res, wip, size_data));
}
