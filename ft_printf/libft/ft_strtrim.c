/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libft.h"

static int	ft_siztrfrt(char const *s1, char const *set)
{
	int	n;
	int	m;

	n = 0;
	m = 0;
	while (set[m])
	{
		if (s1[n] == set[m])
		{
			n++;
			m = 0;
		}
		else
			m++;
	}
	return (n);
}

static int	ft_siztrend(char const *s1, char const *set)
{
	int	n;
	int	m;

	n = 0;
	m = 0;
	while (s1[n])
		n++;
	while (n > 0 && set[m])
	{
		if (s1[n - 1] == set[m])
		{
			n--;
			m = 0;
		}
		else
			m++;
	}
	return (n);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	int		n;
	int		m;
	int		i;

	i = 0;
	n = ft_siztrfrt(s1, set);
	m = ft_siztrend(s1, set);
	if (m < n)
		n = m;
	if (!(st = malloc(sizeof(char) * (m - n + 1))))
		return (NULL);
	while (n + i < m)
	{
		st[i] = s1[n + i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
