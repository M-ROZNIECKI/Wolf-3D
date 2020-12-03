/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libflag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 18:02:38 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFLAG_H
# define LIBFLAG_H
# include "../libftprintf.h"

char	*ft_apost(char *res);
char	*ft_hash(char *res, t_printf *wip, size_t size_data);
char	*ft_hflag(t_printf *wip);
char	*ft_hhflag(t_printf *wip);
char	*ft_lflag(t_printf *wip);
char	*ft_llflag(t_printf *wip);
char	*ft_plus(char *res, t_printf *wip);
int		ft_precision(char **res, t_printf *wip, int size_d);
char	*ft_size_champ(char *res, t_printf *wip, size_t size_data);
char	*ft_space(char *res);
char	*ft_zero(char *res, t_printf *wip, size_t size_d);
#endif
