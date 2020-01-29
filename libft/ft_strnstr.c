/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 16:16:05 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 10:03:57 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	m;

	n = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while ((n < len) && (haystack[n] != '\0'))
	{
		m = 0;
		while ((haystack[n + m] == needle[m]) && ((n + m) < len) &&
				(haystack[n + m] != '\0'))
			m++;
		if (needle[m] == '\0')
			return ((char *)(haystack + n));
		n++;
	}
	return (NULL);
}
