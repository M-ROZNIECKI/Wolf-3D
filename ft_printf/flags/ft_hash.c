/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hash.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 15:04:18 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 17:18:56 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_hash(char *res, t_printf *wip, size_t size_data)
{
	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		((wip->flags & POINT) == 0) && ((wip->flags & PLUS) == 0))
	{
		wip->size_champ -= 2;
		if ((wip->conv == X_MIN) || (wip->conv == P_MIN))
			return (ft_strjoinmod("0x", ft_zero(res, wip, size_data), 2));
		if (wip->conv == X_MAJ)
			return (ft_strjoinmod("0X", ft_zero(res, wip, size_data), 2));
		if (wip->conv == O_MIN)
			wip->size_champ += 1;
		return (ft_strjoinmod("0", ft_zero(res, wip, size_data), 2));
	}
	if ((wip->conv == X_MIN) || (wip->conv == P_MIN))
		return (ft_strjoinmod("0x", res, 2));
	else if (wip->conv == X_MAJ)
		return (ft_strjoinmod("0X", res, 2));
	else if (wip->conv == O_MIN)
		return (ft_strjoinmod("0", res, 2));
	else
		return (res);
}
