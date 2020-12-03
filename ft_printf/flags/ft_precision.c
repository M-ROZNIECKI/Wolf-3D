/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precision.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:03:32 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 20:36:39 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static int	ft_cutlstr(char *res, t_printf *wip)
{
	int preci;

	preci = wip->precision;
	if (((((res[preci - 1] >> 4) & 0x0e) == 0b01100) ||
			(((res[preci - 1] >> 4) & 0x0f) == 0b01110) ||
			(((res[preci - 1] >> 3) & 0x01f) == 0b011110)) && preci >= 1)
		return (preci - 1);
	else if (((((res[preci - 2] >> 4) & 0x0f) == 0b01110) ||
			(((res[preci - 2] >> 3) & 0x01f) == 0b011110)) && preci >= 2)
		return (preci - 2);
	else if ((((res[preci - 3] >> 3) & 0x01f) == 0b011110) && preci >= 3)
		return (preci - 3);
	else
		return (preci);
}

static int	ft_prec_smin(char **res, t_printf *wip)
{
	char	*prec;
	int		newstrl;

	newstrl = wip->precision;
	if (newstrl == 0)
		prec = ft_strdup("");
	else
	{
		if ((wip->flags & L_MIN) != 0)
			newstrl = ft_cutlstr(*res, wip);
		if (!(prec = calloc(sizeof(char), (newstrl + 1))))
			return (0);
		prec = ft_memcpy(prec, *res, (sizeof(char) * newstrl));
	}
	free(*res);
	*res = prec;
	return (newstrl);
}

static int	ft_precnum(char **res, t_printf *wip, int size_d)
{
	char *temp;

	if (*res[0] == '-')
	{
		if (!(temp = calloc(sizeof(char), (wip->precision - size_d + 2))))
			return (0);
		temp = ft_memset(temp, '0', wip->precision++ - size_d + 1);
		temp = ft_strjoinmod("-", ft_strjoinmod(temp, *res + 1, 1), 2);
		free(*res);
		*res = temp;
	}
	else
	{
		if (!(temp = calloc(sizeof(char), (wip->precision - size_d + 1))))
			return (0);
		temp = ft_memset(temp, '0', wip->precision - size_d);
		*res = ft_strjoinmod(temp, *res, 3);
	}
	return (wip->precision);
}

int			ft_precision(char **res, t_printf *wip, int size_d)
{
	if (wip->precision == 0 && ((wip->conv == S_MIN) || ((ft_atoi(*res) == 0 &&
	((wip->conv == D_MIN) || (wip->conv == U_MIN) || (wip->conv == I_MIN) ||
	(wip->conv == O_MIN && ((wip->flags & HASH) == 0)))) ||
	(((wip->conv == X_MAJ) || (wip->conv == X_MIN) || (wip->conv == P_MIN)) &&
	*res[0] == '0'))))
	{
		free(*res);
		wip->flags = wip->flags & ~HASH;
		*res = ft_strdup("");
		return (0);
	}
	if (((wip->conv == X_MAJ) || (wip->conv == X_MIN) || (wip->conv == D_MIN) ||
		(wip->conv == U_MIN) || (wip->conv == I_MIN) || (wip->conv == O_MIN) ||
		(wip->conv == P_MIN)) &&
		(size_d <= wip->precision))
		return (ft_precnum(res, wip, size_d));
	if ((wip->conv == S_MIN) && (wip->precision < size_d))
		return (ft_prec_smin(res, wip));
	return (size_d);
}
