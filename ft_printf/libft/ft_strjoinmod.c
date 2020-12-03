/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freejoin(char *s1, char *s2, int option)
{
	if (option == 1)
		free(s1);
	else if (option == 2)
		free(s2);
	else if (option == 3)
	{
		free(s1);
		free(s2);
	}
}

char		*ft_strjoinmod(char *s1, char *s2, int option)
{
	unsigned int	n;
	unsigned int	m;
	unsigned int	pos;
	char			*s3;

	n = 0;
	m = 0;
	pos = 0;
	while (s1[n] != '\0')
		n++;
	while (s2[m] != '\0')
		m++;
	if (!(s3 = malloc(sizeof(char) * (n + m + 1))))
		return (NULL);
	while (pos < (n + m))
	{
		if (pos < n)
			s3[pos] = s1[pos];
		else
			s3[pos] = s2[pos - n];
		pos++;
	}
	s3[pos] = '\0';
	ft_freejoin(s1, s2, option);
	return (s3);
}
