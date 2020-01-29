/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 15:41:13 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 15:42:36 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dsti;
	unsigned char const	*srci;

	srci = src;
	dsti = dst;
	if (dst == NULL && src == NULL)
		return (dst);
	while (n > 0)
	{
		dsti[n - 1] = srci[n - 1];
		n--;
	}
	return (dst);
}
