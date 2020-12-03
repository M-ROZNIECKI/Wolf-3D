/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gmin_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libconv.h"

static char	*ft_trunc_zero(char *res, int n, int i)
{
	while (res[--n] == '0')
	{
		res[n] = '\0';
		res = ft_strjoinmod(res, &res[n + 1], 1);
	}
	if ((n + 1) - i > 0)
		if (ft_strncmp(&res[(n + 1) - i], localeconv()->decimal_point, i)
		== 0)
		{
			res[(n + 1) - i] = '\0';
			res = ft_strjoinmod(res, &res[n + 1], 1);
		}
	return (res);
}

static char	*ft_fmin(int pre, long double pow, long double ret, t_printf *wip)
{
	int		tmp;

	tmp = pre;
	while (((pow > ret && ret >= 0) || (pow > -ret && -ret >= 0)) &&
	(ret != 0))
	{
		pow = pow / 10.0;
		tmp--;
	}
	return (ft_fmin_conv(wip, ret, pre - tmp - 1));
}

static char	*ft_gmin_utils(char *res, t_printf *wip)
{
	int n;
	int i;
	int deci;

	n = 0;
	deci = 0;
	i = ft_strlen(localeconv()->decimal_point);
	while (res[n] != 'e' && res[n] && ((deci == 1 && res[n] >= '0' &&
		res[n] <= '9') || deci == 0))
		if (ft_strncmp(&res[(n++ + 1) - i], localeconv()->decimal_point, i)
		== 0)
			deci = 1;
	if (deci == 1 && (wip->flags & HASH) == 0)
		res = ft_trunc_zero(res, n, i);
	return (res);
}

char		*ft_gmin_conv(t_printf *wip, long double ret, int pre)
{
	int			tmp;
	long double	pow;
	char		*res;
	int			size_res;

	pow = 1;
	if (pre == 0)
		pre = 1;
	tmp = pre;
	while (tmp--)
		pow = pow * 10.0;
	if (ret >= pow || (ret < 0.0001 && -ret < 0.0001 && ret != 0) ||
	-ret >= pow)
		res = ft_emin_conv(wip, ret, pre - 1);
	else
		res = ft_fmin(pre, pow, ret, wip);
	res = ft_gmin_utils(res, wip);
	size_res = ft_strlen(res);
	if (((wip->flags & PLUS) != 0) && ((wip->flags & ZERO) == 0))
		res = ft_plus(res, wip);
	if (size_res >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_res));
}
