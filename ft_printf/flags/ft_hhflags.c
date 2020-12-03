/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hhflags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:50:29 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 05:17:19 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_short_hexa(t_printf *wip)
{
	unsigned char temp;

	temp = (unsigned char)va_arg(wip->ap, unsigned int);
	if (wip->conv == X_MIN)
		return (ft_hhitoa_base(temp, "0123456789abcdef"));
	else if (wip->conv == X_MAJ)
		return (ft_hhitoa_base(temp, "0123456789ABCDEF"));
	else if (wip->conv == U_MIN)
		return (ft_hhitoa_base(temp, "0123456789"));
	else
		return (ft_hhitoa_base(temp, "01234567"));
}

static char	*ft_short_num(t_printf *wip)
{
	char temp;

	temp = (char)va_arg(wip->ap, int);
	return (ft_itoa((int)temp));
}

static char	*ft_char_nconv(t_printf *wip)
{
	long long	*res;
	char		*arg;

	arg = va_arg(wip->ap, char *);
	if (arg != NULL)
	{
		if (!(res = malloc(sizeof(long long))))
			return (NULL);
		*res = 0;
		if (res != NULL)
			wip->strdone = ft_join_ns(wip->strdone, "", res, 1);
		*arg = (char)*res;
		free(res);
	}
	return ("OK");
}

char		*ft_hhflag(t_printf *wip)
{
	if (wip->conv == X_MAJ || wip->conv == X_MIN || wip->conv == U_MIN ||
		wip->conv == O_MIN)
		return (ft_short_hexa(wip));
	if (wip->conv == I_MIN || wip->conv == D_MIN)
		return (ft_short_num(wip));
	if (wip->conv == N_MIN)
		ft_char_nconv(wip);
	return ("");
}
