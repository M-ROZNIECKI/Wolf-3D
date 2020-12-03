/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	malsize(int n)
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

char		*ft_itoa(int n)
{
	int		m;
	long	temp;
	char	*s;

	temp = n;
	m = malsize(n);
	if (!(s = malloc(sizeof(char) * m)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		temp = -temp;
	}
	s[m - 1] = '\0';
	while ((m > 2 && n < 0) || (m > 1 && n >= 0))
	{
		s[m - 2] = (temp % 10) + 48;
		temp = temp / 10;
		m--;
	}
	return (s);
}
