/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cmin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 08:52:17 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 09:24:43 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

static void	ft_killflags(t_printf *wip)
{
	wip->flags = wip->flags & ~SPACE;
	wip->flags = wip->flags & ~PLUS;
	wip->flags = wip->flags & ~POINT;
}

char		*ft_cmin_conv(t_printf *wip)
{
	char	*res;
	int		size_data;

	ft_killflags(wip);
	if ((wip->flags & L_MIN) != 0)
		res = ft_lflag(wip);
	else
	{
		if (!(res = malloc(sizeof(char) * 2)))
			return (NULL);
		res[0] = (char)va_arg(wip->ap, int);
		res[1] = '\0';
	}
	if (res[0] == 0)
	{
		wip->size_strdone++;
		size_data = 1;
		res = ft_strdup("");
	}
	else
		size_data = ft_strlen(res);
	if (wip->size_champ <= size_data)
		return (res);
	return (ft_size_champ(res, wip, size_data));
}
