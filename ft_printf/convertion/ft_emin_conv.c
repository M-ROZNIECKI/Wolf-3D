/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_emin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 03:29:29 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 12:36:39 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

static char	*ft_deci_part(long double *ret, int *i, int pre)
{
	while ((*ret >= 10) || ((*ret < 1) && *ret != 0))
	{
		if (*ret >= 10)
		{
			*ret = *ret / 10.0;
			(*i)++;
		}
		else
		{
			*ret = *ret * 10.0;
			(*i)--;
		}
	}
	*ret = *ret + ft_flt_bnk_rnd(pre, *ret);
	if (*ret >= 10)
	{
		*ret = *ret / 10.0;
		(*i)++;
	}
	return (ft_itoa((int)(*ret)));
}

static char	*ft_emin_preci(long double ret, int pre, char *res)
{
	res = ft_strjoinmod(res, localeconv()->decimal_point, 1);
	while (pre-- > 0)
	{
		ret = ret * 10;
		res = ft_strjoinmod(res, ft_itoa((int)ret), 3);
		ret -= (long double)((int)ret);
	}
	return (res);
}

static char	*ft_emin_exp(int i, char *res)
{
	if (i < 0)
	{
		res = ft_strjoinmod(res, "e-", 1);
		i = -i;
	}
	else
		res = ft_strjoinmod(res, "e+", 1);
	if (i < 10)
		res = ft_strjoinmod(res, "0", 1);
	return (ft_strjoinmod(res, ft_itoa(i), 3));
}

static char	*ft_emin_num(long double ret, t_printf *wip, int pre)
{
	int			i;
	char		*res;

	i = 0;
	if (ft_signbit((double)ret, wip))
		ret = -ret;
	res = ft_deci_part(&ret, &i, pre);
	ret -= (long double)((int)ret);
	if ((((wip->flags & POINT) != 0) && (pre > 0)) ||
		((wip->flags & POINT) == 0))
		res = ft_emin_preci(ret, pre, res);
	else if ((wip->flags & HASH) != 0)
		res = ft_strjoinmod(res, ".", 1);
	res = ft_emin_exp(i, res);
	if (wip->neg == '1')
		res = ft_strjoinmod("-", res, 2);
	return (res);
}

char		*ft_emin_conv(t_printf *wip, long double ret, int pre)
{
	char		*res;
	int			size_res;

	if (!(res = ft_checkvalue((double)ret, wip)))
		res = ft_emin_num(ret, wip, pre);
	size_res = ft_strlen(res);
	if (((wip->flags & PLUS) != 0) && (((wip->flags & ZERO) == 0) ||
		(wip->size_champ <= size_res)) && (wip->conv == E_MIN))
		res = ft_plus(res, wip);
	if (size_res < wip->size_champ && (wip->conv == E_MIN))
		return (ft_size_champ(res, wip, size_res));
	return (res);
}
