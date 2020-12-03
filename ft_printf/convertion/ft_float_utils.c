/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libconv.h"

int			ft_signbit(double d, t_printf *wip)
{
	t_doubles u;

	u.d = d;
	if (u.bits.sign)
		wip->neg = '1';
	return (u.bits.sign);
}

char		*ft_checkvalue(double ret, t_printf *wip)
{
	t_doubles	u;
	char		*res;

	u.d = ret;
	res = NULL;
	if (u.bits.exp == 0x7ff)
		wip->flags = wip->flags & ~ZERO;
	if ((u.bits.exp == 0x7ff) && (u.bits.manh == 0) && (u.bits.manl == 0) &&
	(u.bits.sign == 0))
		res = ft_strdup("inf");
	else if ((u.bits.exp == 0x7ff) && (u.bits.manh == 0) &&
			(u.bits.manl == 0) && (u.bits.sign == 1))
		res = ft_strdup("-inf");
	else if (u.bits.exp == 0x7ff)
	{
		res = ft_strdup("nan");
		wip->flags = wip->flags & ~PLUS;
	}
	return (res);
}

long double	ft_flt_bnk_rnd(int i, long double ret)
{
	long long	tmp;
	long double	rnd_up;
	int			n;

	tmp = (long long)ret;
	ret -= tmp;
	n = i;
	rnd_up = 0.5;
	while (i > 0)
	{
		while ((i-- > 0) && ret < 1844674407370955161.6)
			ret = ret * 10;
		tmp = (long long)ret;
		ret -= tmp;
	}
	if (ret == 0.5)
		if ((tmp % 2) == 0)
			return (0);
	while (n-- > 0)
		rnd_up = rnd_up / 10.0;
	return (rnd_up);
}
