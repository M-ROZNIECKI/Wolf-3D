/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 15:42:54 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/05 19:17:59 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

static char	*ft_intselect(t_printf *wip)
{
	char	*res;

	if ((wip->flags & L_MIN) != 0)
		res = ft_lflag(wip);
	else if ((wip->flags & LL_MIN) != 0)
		res = ft_llflag(wip);
	else if ((wip->flags & H_MIN) != 0)
		res = ft_hflag(wip);
	else if ((wip->flags & HH_MIN) != 0)
		res = ft_hhflag(wip);
	else
		res = ft_itoa(va_arg(wip->ap, int));
	return (res);
}

char		*ft_dmin_conv(t_printf *wip)
{
	char	*res;
	int		size_res;

	res = ft_intselect(wip);
	size_res = ft_strlen(res);
	if ((wip->flags & APOST) != 0)
		res = ft_apost(res);
	if ((wip->flags & POINT) != 0)
		size_res = ft_precision(&res, wip, size_res);
	if (((wip->flags & PLUS) != 0) && (((wip->flags & ZERO) == 0) ||
	((wip->flags & POINT) != 0) || (wip->size_champ <= size_res)))
		res = ft_plus(res, wip);
	if (res[0] == '-')
		wip->neg = '1';
	if (size_res >= wip->size_champ)
		return (res);
	return (ft_size_champ(res, wip, size_res));
}
