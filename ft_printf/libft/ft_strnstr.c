/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	m;

	n = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while ((n < len) && (haystack[n] != '\0'))
	{
		m = 0;
		while ((haystack[n + m] == needle[m]) && ((n + m) < len) &&
				(haystack[n + m] != '\0'))
			m++;
		if (needle[m] == '\0')
			return ((char *)(haystack + n));
		n++;
	}
	return (NULL);
}
