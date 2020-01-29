/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 09:28:04 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 09:06:35 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	malsize(int n)
{
	int m;

	m = 2;
	if (n > 0)
		m = 1;
	while (n != 0)
	{
		n = n / 10;
		m++;
	}
	return (m);
}

char		*ft_itoa(int n)
{
	int		m;
	long	temp;
	char	*s;

	temp = n;
	m = malsize(n);
	if (!(s = malloc(sizeof(char) * m)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		temp = -temp;
	}
	s[m - 1] = '\0';
	while ((m > 2 && n < 0) || (m > 1 && n >= 0))
	{
		s[m - 2] = (temp % 10) + 48;
		temp = temp / 10;
		m--;
	}
	return (s);
}
