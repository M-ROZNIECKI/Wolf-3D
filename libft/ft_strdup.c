/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 11:20:33 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 11:02:22 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	i++;
	if (!(s2 = malloc(sizeof(char) * i)))
		return (NULL);
	while (i > 0)
	{
		s2[i - 1] = s1[i - 1];
		i--;
	}
	return (s2);
}
