/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	len_champ(t_printf *wip, int i)
{
	if (wip->formats[i] == '0')
		wip->flags = wip->flags | ZERO;
	if (wip->formats[i] == '*' ||
		(wip->formats[i] == '0' && wip->formats[i + 1] == '*'))
	{
		wip->size_champ = va_arg(wip->ap, size_t);
		if (wip->size_champ < 0)
		{
			wip->size_champ = -wip->size_champ;
			wip->flags = wip->flags | MINUS;
		}
		if (wip->formats[i] == '0')
			i++;
		i++;
	}
	else
	{
		wip->size_champ = wip->formats[i++] - '0';
		while (wip->formats[i] >= '0' && wip->formats[i] <= '9')
		{
			wip->size_champ = wip->size_champ * 10 + (wip->formats[i++] - '0');
		}
	}
	return (i);
}

static void	fill_sym(t_printf *wip, int n)
{
	if (n < 14)
		wip->conv = 1 << n;
	else if (n < 18)
		wip->flags = wip->flags | (1 << (n - 14));
	else if (n == 18)
	{
		if ((wip->flags & H_MIN) != 0)
			wip->flags = (wip->flags & ~H_MIN) | HH_MIN;
		else
			wip->flags = wip->flags | H_MIN;
	}
	else if (n == 19)
	{
		if ((wip->flags & L_MIN) != 0)
			wip->flags = (wip->flags & ~L_MIN) | LL_MIN;
		else
			wip->flags = wip->flags | L_MIN;
	}
	else
		wip->flags = wip->flags | (1 << (n - 12));
}

static int	check(t_printf *wip, int i)
{
	int		n;

	n = -1;
	if (wip->formats[i] == '*')
		wip->precision = va_arg(wip->ap, int);
	while (SYMBOL[++n] != '\0')
	{
		if (wip->formats[i] == SYMBOL[n])
		{
			if (((SYMBOL[n] == '0') && ((wip->flags & POINT) == 0)) ||
				((SYMBOL[n] != '0')))
				fill_sym(wip, n);
			return (0);
		}
	}
	if (SYMBOL[n] == '\0' && (wip->formats[i] > '9' || wip->formats[i] < '0'))
		return (-1);
	if ((wip->formats[i - 1] == '.') && (wip->formats[i] != '*'))
		wip->precision = ft_atoi(&wip->formats[i]);
	return (1);
}

static void	ft_init(t_printf *wip, int *i)
{
	int	fail;

	wip->conv = INIT_C;
	wip->flags = INIT_F;
	wip->precision = 0;
	wip->size_champ = 0;
	wip->neg = '0';
	wip->size_strdone = 0;
	wip->formats[*i] = '\0';
	fail = 0;
	while (wip->formats[++(*i)] && wip->conv == 0 && fail != -1)
	{
		if (((wip->formats[*i] >= '0' && wip->formats[*i] <= '9') ||
			wip->formats[*i] == '*') && ((wip->flags & POINT) == 0))
			*i = len_champ(wip, *i);
		fail = check(wip, *i);
		if (fail == -1)
			(*i)--;
	}
}

int			ft_parse(t_printf *wip, int *i, int n)
{
	char		*temp_form;
	long long	len;

	ft_init(wip, i);
	temp_form = ft_localetest(wip, i, n);
	if (wip->error == 1)
		return (n);
	len = ft_strlen(&wip->formats[n]);
	wip->strdone = ft_join_ns(wip->strdone, &wip->formats[n], &len, 1);
	if (temp_form == NULL)
		temp_form = ch_conv1(wip);
	len = 1;
	if ((wip->flags & SPACE) && (wip->neg == '0'))
		wip->strdone = ft_join_ns(wip->strdone, " ", &len, 1);
	if (wip->conv == C_MIN && temp_form[0] == 0)
		wip->size_strdone += wip->size_champ;
	wip->size_strdone += ft_strlen(temp_form);
	wip->strdone = ft_join_ns(wip->strdone, temp_form, &wip->size_strdone, 3);
	*i = *i - 1;
	return (*i + 1);
}
