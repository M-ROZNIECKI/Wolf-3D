/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apost.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:32:26 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 00:51:32 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char	*ft_apost(char *res)
{
	int		i;
	int		n;
	char	*new;
	char	*temp;

	i = -1;
	n = 0;
	if (!(new = ft_calloc(sizeof(char), 1)))
		return (NULL);
	if (res[0] == '-')
		n = 1;
	while (res[++i + n] >= '0' && res[i + n] <= '9')
		n = n + i - i;
	while (i > 3)
	{
		i -= 3;
		temp = ft_strjoin(localeconv()->thousands_sep, (res + i + n));
		res[i + n] = '\0';
		new = ft_strjoinmod(temp, new, 3);
	}
	new = ft_strjoinmod(res, new, 3);
	return (new);
}
