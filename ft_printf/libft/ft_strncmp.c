/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				m;
	unsigned char const	*st1;
	unsigned char const	*st2;

	st1 = (unsigned char const *)s1;
	st2 = (unsigned char const *)s2;
	m = 0;
	if (n == 0)
		return (0);
	while ((st1[m] == st2[m]) && (m < (n - 1)))
	{
		if (st1[m] == '\0')
			return (0);
		m++;
	}
	return (st1[m] - st2[m]);
}
