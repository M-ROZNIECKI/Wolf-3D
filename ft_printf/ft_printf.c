/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	i check the len of nl_langinfo(CODESET), because if its a void string,
**	it means that it take the global system encodage for char
**	(UTF-8 US-ASCII or other)
*/

static t_printf	*ft_init(const char *format, int *i, int *n)
{
	t_printf	*wip;
	char		*str;

	if (!(wip = malloc(sizeof(t_printf))))
		return (0);
	wip->formats = ft_strdup(format);
	wip->strdone = ft_strdup("");
	wip->size_strdone = 0;
	str = ft_strdup(setlocale(LC_ALL, NULL));
	if (ft_strlen(nl_langinfo(CODESET)) == 0)
	{
		setlocale(LC_ALL, "");
		wip->strloc = ft_strdup(nl_langinfo(CODESET));
		setlocale(LC_ALL, str);
	}
	else
		wip->strloc = ft_strdup(nl_langinfo(CODESET));
	free(str);
	wip->error = 0;
	*i = -1;
	*n = 0;
	return (wip);
}

static void		ft_free_wip(t_printf *wip)
{
	free(wip->formats);
	free(wip->strdone);
	free(wip->strloc);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			n;
	t_printf	*wip;

	wip = ft_init(format, &i, &n);
	va_start(wip->ap, format);
	while (wip->formats[++i] != '\0')
		if (wip->formats[i] == '%')
			n = ft_parse(wip, &i, n);
	wip->size_strdone = i - n;
	wip->strdone = ft_join_ns(wip->strdone, &(wip->formats[n]),
	&(wip->size_strdone), -1);
	i = write(1, wip->strdone, wip->size_strdone);
	va_end(wip->ap);
	ft_free_wip(wip);
	if (wip->error == 1)
		i = -1;
	free(wip);
	return (i);
}
