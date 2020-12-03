/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:44:23 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:44:23 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	n;

	n = 0;
	if (ft_strlen(s) <= start)
		len = 0;
	if (!(subs = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((s[start + n] != '\0') && (n < len))
	{
		subs[n] = s[start + n];
		n++;
	}
	subs[n] = '\0';
	return (subs);
}
