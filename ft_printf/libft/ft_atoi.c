/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned int		i;
	unsigned int		n;
	long long			res;

	i = 0;
	n = 0;
	res = 0;
	while (((str[n] >= 9) && (str[n] <= 13)) || (str[n] == 32))
		n++;
	if ((str[n] == '-') || (str[n] == '+'))
		i++;
	while ((str[i + n] > 47) && (str[i + n] < 58))
	{
		res = res * 10 + str[i + n] - 48;
		i++;
		if (str[n] == '-' && res < 0)
			return (0);
		if (str[n] != '-' && res > 4294967295)
			return (-1);
	}
	if (str[n] == '-')
		res = -res;
	return ((int)res);
}
