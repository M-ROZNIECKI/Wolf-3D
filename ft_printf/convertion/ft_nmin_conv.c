/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmin_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:38 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libconv.h"

static char	*ft_nmin_int(t_printf *wip)
{
	long long	*res;
	int			*arg;

	arg = va_arg(wip->ap, int *);
	if (arg != NULL)
	{
		if (!(res = malloc(sizeof(long long))))
			return (NULL);
		*res = 0;
		if (res != NULL)
			wip->strdone = ft_join_ns(wip->strdone, "", res, 1);
		*arg = (int)*res;
		free(res);
	}
	return ("");
}

char		*ft_nmin_conv(t_printf *wip)
{
	char		*voidstr;

	if (!(voidstr = ft_calloc(1, sizeof(char))))
		return (NULL);
	if ((wip->flags & L_MIN) != 0)
		ft_lflag(wip);
	else if ((wip->flags & LL_MIN) != 0)
		ft_llflag(wip);
	else if ((wip->flags & H_MIN) != 0)
		ft_hflag(wip);
	else if ((wip->flags & HH_MIN) != 0)
		ft_hhflag(wip);
	else
		ft_nmin_int(wip);
	return (voidstr);
}
