/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmin_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:38 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
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
		res = ft_itoa_base(va_arg(wip->ap, unsigned int), "0123456789abcdef");
	return (res);
}

char		*ft_xmin_conv(t_printf *wip)
{
	char	*res;
	int		size_data;

	wip->flags = wip->flags & ~SPACE;
	wip->flags = wip->flags & ~PLUS;
	res = ft_select_size(wip);
	size_data = ft_strlen(res);
	if (res[0] == '0')
		wip->flags = wip->flags & ~HASH;
	if ((wip->flags & POINT) != 0)
		size_data = ft_precision(&res, wip, size_data);
	if ((wip->flags & HASH) == HASH)
		res = ft_hash(res, wip, size_data);
	if ((((wip->flags & (HASH + POINT)) == HASH) && (res[1] == 'x')) ||
		((wip->flags & (HASH + POINT)) == HASH + POINT))
		wip->flags = wip->flags & ~HASH;
	size_data = ft_strlen(res);
	if (wip->size_champ <= size_data)
		return (res);
	return (ft_size_champ(res, wip, size_data));
}
