/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:35:45 by fenrir            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/12 03:05:42 by fenrir           ###   ########lyon.fr   */
=======
/*   Updated: 2020/05/02 10:35:08 by fenrir           ###   ########lyon.fr   */
>>>>>>> test_map
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

static void	ft_init_w(t_win *win)
{
	win->my_mlx = mlx_init();
	win->win = mlx_new_windows(win->my_mlx, win->res_x, win->res_y, win->name);
}

void		ft_init(t_wolf *wolf)
{
	ft_init_map(wolf);
<<<<<<< HEAD
	ft_init_w(&wolf->win);
	ft_init_tex(wolf);
=======
	//ft_init_w(&wolf->win);
>>>>>>> test_map
}