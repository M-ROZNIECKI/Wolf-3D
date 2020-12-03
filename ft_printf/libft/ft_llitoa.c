/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	malsize(long long n)
{
	int m;

	m = 2;
	if (n > 0)
		m = 1;
	while (n != 0)
	{
		n = n / 10;
		m++;
	}
	return (m);
}

char		*ft_llitoa(long long n)
{
	int			m;
	long long	temp;
	char		*s;

	temp = n;
	m = malsize(n);
	if (!(s = malloc(sizeof(char) * m)))
		return (NULL);
	if (n == -9223372036854775807)
		return (ft_memcpy(s, "-9223372036854775807", (sizeof(char) * 21)));
	if (n < 0)
		s[0] = '-';
	s[m - 1] = '\0';
	while ((m > 2 && n < 0) || (m > 1 && n >= 0))
	{
		if ((temp % 10) < 0)
			s[m - 2] = 48 - (temp % 10);
		else
			s[m - 2] = (temp % 10) + 48;
		temp = temp / 10;
		m--;
	}
	return (s);
}
