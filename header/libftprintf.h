/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:37 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <locale.h>
# include <langinfo.h>
# include <wchar.h>
# include "libft.h"

/*
**	conv contain convert symbol in this order :
**	MSB(most significant bite) (complet with 0) nfgecspdiuxX% LSB
**
**	flags contains flags in this order : + space # ' l ll h hh - 0 . *
*/

typedef struct		s_printf
{
	va_list		ap;
	short		conv;
	short		flags;
	char		*formats;
	char		*strdone;
	char		*strloc;
	char		neg;
	int			precision;
	int			size_champ;
	char		error;
	long long	size_strdone;
}					t_printf;

# define SYMBOL		"%Xxuidpscegfno*.0-hl'# +"

# define INIT_C		0x0000

# define PERCENT	0x0001
# define X_MAJ		0x0002
# define X_MIN		0x0004
# define U_MIN		0x0008
# define I_MIN		0x0010
# define D_MIN		0x0020
# define P_MIN		0x0040
# define S_MIN		0x0080
# define C_MIN		0x0100
# define E_MIN		0x0200
# define G_MIN		0x0400
# define F_MIN		0x0800
# define N_MIN		0x1000
# define O_MIN		0x2000

# define INIT_F		0x0000

# define STAR		0x0001
# define POINT		0x0002
# define ZERO		0x0004
# define MINUS		0x0008
# define HH_MIN		0x0010
# define H_MIN		0x0020
# define LL_MIN		0x0040
# define L_MIN		0x0080
# define APOST		0x0100
# define HASH		0x0200
# define SPACE		0x0400
# define PLUS		0x0800

int					ft_printf (const char *format,
					...) __attribute__((format(printf,1,2)));
int					ft_parse(t_printf *wip, int *i, int n);
char				*ch_conv1(t_printf *wip);
char				*ft_char_conv(wchar_t origin, t_printf *wip);
char				*ft_localetest(t_printf *wip, int *i, int n);

#endif
