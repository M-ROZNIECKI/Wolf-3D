/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 13:36:21 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 20:32:57 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

char	*ft_pmin_conv(t_printf *wip)
{
	unsigned long	res;
	char			*str;
	int				size_data;

	wip->flags = wip->flags & ~SPACE;
	wip->flags = wip->flags & ~PLUS;
	res = (unsigned long)va_arg(wip->ap, void *);
	str = ft_litoa_base(res, "0123456789abcdef");
	size_data = ft_strlen(str);
	if ((wip->flags & POINT) != 0)
		size_data = ft_precision(&str, wip, size_data);
	str = ft_hash(str, wip, size_data);
	wip->size_champ -= 2;
	wip->flags = wip->flags & ~ZERO;
	if (wip->size_champ <= size_data)
		return (str);
	return (ft_size_champ(str, wip, size_data));
}
