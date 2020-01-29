/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:42:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/12 11:56:00 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		m;

	m = 0;
	s2 = (char *)s;
	while (s2[m] != '\0')
		m++;
	while (m >= 0)
	{
		if (s2[m] == (char)c)
			return ((s2 + m));
		m--;
	}
	return (NULL);
}
