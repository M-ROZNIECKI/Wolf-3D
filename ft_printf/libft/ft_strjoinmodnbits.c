/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmodnbits.c                               :+:      :+:    :+:   */
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
	if ((option == 1) || (option == -1))
		free(s1);
	else if (option == 2)
		free(s2);
	else if (option == 3)
	{
		free(s1);
		free(s2);
	}
}

char		*ft_join_ns(char *s1, char *s2, long long *nchar, int option)
{
	static unsigned int	n = 0;
	unsigned int		pos;
	char				*s3;

	pos = 0;
	if (!(s3 = malloc(sizeof(char) * (n + *nchar + 1))))
		return (NULL);
	while (pos < (n + *nchar))
	{
		if (pos < n)
			s3[pos] = s1[pos];
		else
			s3[pos] = s2[pos - n];
		pos++;
	}
	s3[pos] = '\0';
	*nchar = pos;
	n = pos;
	if (option == -1)
		n = 0;
	ft_freejoin(s1, s2, option);
	return (s3);
}
