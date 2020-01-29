/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:27:11 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 16:28:43 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dsti;
	unsigned char const	*srci;
	unsigned int		m;

	m = 0;
	srci = src;
	dsti = dst;
	while (n > m)
	{
		dsti[m] = srci[m];
		m++;
		if (dsti[m - 1] == (unsigned char)c)
			return (dsti + m);
	}
	return (NULL);
}
