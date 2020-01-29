/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 17:00:44 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 10:34:48 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	while (s[i])
		i++;
	if (!(s2 = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s2[i] = '\0';
	while (i > 0)
	{
		s2[i - 1] = f((i - 1), s[i - 1]);
		i--;
	}
	return (s2);
}
