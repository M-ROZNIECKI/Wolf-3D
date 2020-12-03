/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_short_hexa(t_printf *wip)
{
	unsigned short temp;

	temp = (unsigned short)va_arg(wip->ap, unsigned int);
	if (wip->conv == X_MIN)
		return (ft_hitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_hitoa_base(temp, "0123456789ABCDEF"));
	else if (wip->conv == U_MIN)
		return (ft_hitoa_base(temp, "0123456789"));
	else
		return (ft_hitoa_base(temp, "01234567"));
}

static char	*ft_short_num(t_printf *wip)
{
	short temp;

	temp = (short)va_arg(wip->ap, int);
	return (ft_itoa((int)temp));
}

static char	*ft_short_nconv(t_printf *wip)
{
	long long	*res;
	short		*arg;

	arg = va_arg(wip->ap, short *);
	if (arg != NULL)
	{
		if (!(res = malloc(sizeof(long long))))
			return (NULL);
		*res = 0;
		if (res != NULL)
			wip->strdone = ft_join_ns(wip->strdone, "", res, 1);
		*arg = (short)*res;
		free(res);
	}
	return ("");
}

char		*ft_hflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN ||
		wip->conv == O_MIN)
		return (ft_short_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_short_num(wip));
	if (wip->conv == N_MIN)
		ft_short_nconv(wip);
	return ("");
}
