/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (dst[i] && i <= size)
		i++;
	if (size < i)
		return (ft_strlen(src) + size);
	while (src[n] != '\0')
	{
		if ((i + n) < size - 1)
			dst[i + n] = src[n];
		if ((i + n) == size - 1)
			dst[i + n] = '\0';
		n++;
	}
	if (i + n <= size - 1)
		dst[i + n] = '\0';
	return (i + n);
}
