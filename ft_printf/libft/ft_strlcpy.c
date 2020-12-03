/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t n;

	n = 0;
	if (size == 0)
		return (ft_strlen(src) + size);
	while ((src[n] != '\0') && (n < size - 1))
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	while (src[n] != '\0')
		n++;
	return (n);
}
