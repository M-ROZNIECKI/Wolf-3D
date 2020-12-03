/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libconv.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 02:30:42 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 19:34:45 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBCONV_H
# define LIBCONV_H
# include "../libftprintf.h"
# include "../flags/libflag.h"

typedef union			u_doubles
{
	double				d;
	struct				s_bits
	{
		unsigned int	manl	:32;
		unsigned int	manh	:20;
		unsigned int	exp		:11;
		unsigned int	sign	:1;
	}					bits;
}						t_doubles;

char					*ft_xmin_conv(t_printf *wip);
char					*ft_xmaj_conv(t_printf *wip);
char					*ft_omin_conv(t_printf *wip);
char					*ft_umin_conv(t_printf *wip);
char					*ft_dmin_conv(t_printf *wip);
char					*ft_perc_conv(t_printf *wip);
char					*ft_cmin_conv(t_printf *wip);
char					*ft_smin_conv(t_printf *wip);
char					*ft_pmin_conv(t_printf *wip);
char					*ft_nmin_conv(t_printf *wip);
char					*ft_efgmin_select(t_printf *wip);
char					*ft_fmin_conv(t_printf *wip, long double ret, int pre);
char					*ft_emin_conv(t_printf *wip, long double ret, int pre);
char					*ft_gmin_conv(t_printf *wip, long double ret, int pre);
int						ft_signbit(double d, t_printf *wip);
long double				ft_flt_bnk_rnd(int i, long double ret);
char					*ft_checkvalue(double ret, t_printf *wip);
#endif
