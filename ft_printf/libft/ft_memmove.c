/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dsti;
	unsigned char const	*srci;
	size_t				m;

	m = 0;
	srci = src;
	dsti = dst;
	if (dst == NULL && src == NULL)
		return (dst);
	if (srci < dsti)
		dsti = ft_memcpy(dsti, srci, len);
	else
	{
		while (len > m)
		{
			dsti[m] = srci[m];
			m++;
		}
	}
	return (dst);
}
