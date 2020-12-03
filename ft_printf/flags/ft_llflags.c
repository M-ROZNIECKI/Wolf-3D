/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_llflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:40:39 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 05:20:04 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_long_hexa(t_printf *wip)
{
	unsigned long long temp;

	temp = va_arg(wip->ap, unsigned long long int);
	if (wip->conv == X_MIN)
		return (ft_llitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_llitoa_base(temp, "0123456789ABCDEF"));
	else if (wip->conv == U_MIN)
		return (ft_llitoa_base(temp, "0123456789"));
	else
		return (ft_llitoa_base(temp, "01234567"));
}

static char	*ft_long_num(t_printf *wip)
{
	long long temp;

	temp = va_arg(wip->ap, long long);
	return (ft_llitoa(temp));
}

static char	*ft_long_nconv(t_printf *wip)
{
	long long	*res;

	res = va_arg(wip->ap, long long *);
	if (res != NULL)
		wip->strdone = ft_join_ns(wip->strdone, "", res, 1);
	return ("");
}

char		*ft_llflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN ||
		wip->conv == O_MIN)
		return (ft_long_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_long_num(wip));
	if (wip->conv == N_MIN)
		ft_long_nconv(wip);
	return ("");
}
