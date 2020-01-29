/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:56:54 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 11:37:11 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dsti;
	unsigned char const	*srci;
	size_t				m;

	m = 0;
	srci = src;
	dsti = dst;
	if (dst == NULL && src == NULL)
		return (dst);
	if (srci < dsti)
		dsti = ft_memcpy(dsti, srci, len);
	else
	{
		while (len > m)
		{
			dsti[m] = srci[m];
			m++;
		}
	}
	return (dst);
}
