/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_efgmin_select.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 05:39:37 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 06:38:23 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_efgmin_select(t_printf *wip)
{
	long double	ret;
	char		*res;
	int			pre;

	ret = (long double)va_arg(wip->ap, double);
	if ((wip->flags & POINT) != 0)
		pre = wip->precision;
	else
		pre = 6;
	if (wip->conv == F_MIN)
		res = ft_fmin_conv(wip, ret, pre);
	else if (wip->conv == E_MIN)
		res = ft_emin_conv(wip, ret, pre);
	else if (wip->conv == G_MIN)
		res = ft_gmin_conv(wip, ret, pre);
	else
		res = ft_strdup("error");
	return (res);
}
