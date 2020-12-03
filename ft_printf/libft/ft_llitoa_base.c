/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_is_legit(char *base, int len)
{
	int n;
	int m;

	n = 0;
	m = 0;
	if (len < 2)
		return (0);
	while (base[m] != '\0')
	{
		while (base[n] != '\0')
		{
			if (base[n] == '+' || base[n] == '-')
				return (0);
			if ((base[n] == base[m]) && (n != m))
				return (0);
			n++;
		}
		n = 0;
		m++;
	}
	return (1);
}

static int	malsize(unsigned long long n, int base_len)
{
	int m;

	m = 2;
	if (n > 0)
		m = 1;
	while (n != 0)
	{
		n = n / base_len;
		m++;
	}
	return (m);
}

char		*ft_llitoa_base(unsigned long long n, char *base)
{
	int					m;
	int					base_len;
	unsigned long long	temp;
	char				*s;

	base_len = ft_strlen(base);
	temp = n;
	if (!(ft_base_is_legit(base, base_len)))
		return (NULL);
	m = malsize(temp, base_len);
	if (!(s = malloc(sizeof(char) * m)))
		return (NULL);
	s[m - 1] = '\0';
	while (m > 1)
	{
		s[m-- - 2] = base[(temp % base_len)];
		temp = temp / base_len;
	}
	return (s);
}
