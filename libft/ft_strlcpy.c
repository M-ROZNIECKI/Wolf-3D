/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 15:38:37 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 12:33:21 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t n;

	n = 0;
	if (size == 0)
		return (ft_strlen(src) + size);
	while ((src[n] != '\0') && (n < size - 1))
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
	while (src[n] != '\0')
		n++;
	return (n);
}
