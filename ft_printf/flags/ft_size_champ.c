/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:38 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libflag.h"

static char	*ft_conv_c(char *res, t_printf *wip, size_t size_data)
{
	char	*temp;
	char	*tmp;

	free(res);
	if (!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 2))))
		return (NULL);
	tmp = &temp[1];
	if ((wip->flags & MINUS) != 0)
	{
		tmp = ft_memset(tmp, ' ', wip->size_champ - size_data);
		wip->size_champ--;
	}
	else
		temp = ft_memset(temp, ' ', wip->size_champ - size_data);
	return (temp);
}

static void	ft_size_modif(t_printf *wip, char *res, size_t *size_data)
{
	if (((wip->flags & SPACE) || (wip->flags & PLUS)) && (wip->neg == '0'))
		(*size_data)++;
	if (((wip->flags & HASH) != 0) && ((wip->conv == X_MAJ ||
		wip->conv == X_MIN) && (res[1] == 'x' || res[1] == 'X')))
		wip->size_champ -= 2;
	if (((wip->flags & HASH) != 0) && wip->conv == O_MIN && res[0] == '0')
		wip->size_champ -= 1;
}

char		*ft_size_champ(char *res, t_printf *wip, size_t size_data)
{
	char	*temp;

	ft_size_modif(wip, res, &size_data);
	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		(((wip->flags & POINT) == 0) || wip->conv == F_MIN) &&
		((wip->flags & PLUS) != 0))
		return (ft_plus(ft_zero(res, wip, size_data), wip));
	if (((wip->flags & ZERO) != 0) && ((wip->flags & MINUS) == 0) &&
		(((wip->flags & POINT) == 0) || (wip->conv == F_MIN) ||
		(wip->conv == E_MIN) || (wip->conv == G_MIN) || (wip->conv == C_MIN) ||
		(wip->conv == S_MIN)) && ((wip->flags & PLUS) == 0))
		return (ft_zero(res, wip, size_data));
	if ((wip->conv == C_MIN) && (res[0] == 0))
		return (ft_conv_c(res, wip, size_data));
	if (!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_data + 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - size_data);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}
