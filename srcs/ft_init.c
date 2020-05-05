/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 12:42:38 by fenrir            #+#    #+#             */
/*   Updated: 2020/05/05 12:42:38 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_init_w(t_win *win)
{
	win->my_mlx = mlx_init();
	win->win = mlx_new_windows(win->my_mlx, win->res_x, win->res_y, "NOP");
}

void	ft_init(t_wolf *wolf)
{
	ft_init_map(wolf);
	//ft_init_w(&wolf->win);
}it_tex(wolf);
}