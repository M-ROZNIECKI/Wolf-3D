/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_zero.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 21:31:15 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 20:12:16 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_zero(char *res, t_printf *wip, size_t size_d)
{
	char	*tmp;
	char	*modif;

	if (!(tmp = ft_calloc(sizeof(char), (wip->size_champ - size_d + 1))))
		return (NULL);
	tmp = ft_memset(tmp, '0', wip->size_champ - size_d);
	if (res[0] != '-')
		return (ft_strjoinmod(tmp, res, 3));
	modif = ft_strjoinmod("-", ft_strjoinmod(tmp, res + 1, 1), 2);
	free(res);
	return (modif);
}
