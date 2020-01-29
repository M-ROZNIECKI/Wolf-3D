/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:28:43 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 10:05:32 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	n;

	n = 0;
	if (ft_strlen(s) <= start)
		len = 0;
	if (!(subs = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while ((s[start + n] != '\0') && (n < len))
	{
		subs[n] = s[start + n];
		n++;
	}
	subs[n] = '\0';
	return (subs);
}
