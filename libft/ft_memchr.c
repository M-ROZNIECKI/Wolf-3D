/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:10:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 10:23:47 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned int	m;

	m = 0;
	s2 = (unsigned char *)s;
	while (n > m)
	{
		if (s2[m] == (unsigned char)c)
			return ((s2 + m));
		m++;
	}
	return (NULL);
}
