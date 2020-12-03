/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utf_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char	*one_char(wchar_t origin)
{
	char *new;

	if (!(new = malloc(sizeof(char) * 2)))
		return (NULL);
	new[0] = (char)origin;
	new[1] = '\0';
	return (new);
}

static char	*two_char(wchar_t origin)
{
	char *new;

	if (!(new = malloc(sizeof(char) * 3)))
		return (NULL);
	new[1] = 0b10000000 | (char)(origin & 0x03f);
	new[0] = 0b11000000 | (char)(origin >> 6);
	new[2] = '\0';
	return (new);
}

static char	*three_char(wchar_t origin)
{
	char *new;

	if (!(new = malloc(sizeof(char) * 4)))
		return (NULL);
	new[2] = 0b10000000 | (char)(origin & 0x03f);
	new[1] = 0b10000000 | (char)((origin >> 6) & 0x03f);
	new[0] = 0b11100000 | (char)(origin >> 12);
	new[3] = '\0';
	return (new);
}

static char	*four_char(wchar_t origin)
{
	char *new;

	if (!(new = malloc(sizeof(char) * 5)))
		return (NULL);
	new[3] = 0b10000000 | (char)(origin & 0x03f);
	new[2] = 0b10000000 | (char)((origin >> 6) & 0x03f);
	new[1] = 0b10000000 | (char)((origin >> 12) & 0x03f);
	new[0] = 0b11110000 | (char)(origin >> 18);
	new[4] = '\0';
	return (new);
}

char		*ft_char_conv(wchar_t origin)
{
	if (origin <= 0x007F)
		return (one_char(origin));
	else if (origin < 0x0800)
		return (two_char(origin));
	else if (origin < 0x010000)
		return (three_char(origin));
	else if (origin < 0x0110000)
		return (four_char(origin));
	else
		return ((char *)calloc(1, sizeof(char)));
}
