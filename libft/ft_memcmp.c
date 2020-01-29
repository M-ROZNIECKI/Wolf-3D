/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 09:00:59 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 15:41:47 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		m;
	unsigned char const	*st1;
	unsigned char const	*st2;

	m = 0;
	st1 = s1;
	st2 = s2;
	if (n == 0)
		return (0);
	while ((st1[m] == st2[m]) && (m < (n - 1)))
		m++;
	return (st1[m] - st2[m]);
}
