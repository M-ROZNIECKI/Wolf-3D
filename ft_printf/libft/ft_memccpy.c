/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dsti;
	unsigned char const	*srci;
	unsigned int		m;

	m = 0;
	srci = src;
	dsti = dst;
	while (n > m)
	{
		dsti[m] = srci[m];
		m++;
		if (dsti[m - 1] == (unsigned char)c)
			return (dsti + m);
	}
	return (NULL);
}
