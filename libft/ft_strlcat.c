/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 16:16:33 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 13:09:54 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (dst[i] && i <= size)
		i++;
	if (size < i)
		return (ft_strlen(src) + size);
	while (src[n] != '\0')
	{
		if ((i + n) < size - 1)
			dst[i + n] = src[n];
		if ((i + n) == size - 1)
			dst[i + n] = '\0';
		n++;
	}
	if (i + n <= size - 1)
		dst[i + n] = '\0';
	return (i + n);
}
