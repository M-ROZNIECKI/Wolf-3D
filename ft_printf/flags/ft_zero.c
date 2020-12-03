/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:38 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
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
