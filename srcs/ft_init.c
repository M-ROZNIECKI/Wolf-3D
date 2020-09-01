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
	win->win = mlx_new_window(win->my_mlx, win->res_x, win->res_y, win->name);
}

void 	ft_init_player(t_wolf *wolf)
{
	wolf->player.x_pos = wolf->map.start_x;
	wolf->player.y_pos = wolf->map.start_y;
	wolf->player.x_dir = 0;
	wolf->player.y_dir = 0;
	if (wolf->map.dir == 'N')
		wolf->player.y_dir = -1;
	if (wolf->map.dir == 'S')
		wolf->player.y_dir = 1;
	if (wolf->map.dir == 'E')
		wolf->player.x_dir = 1;
	if (wolf->map.dir == 'W')
		wolf->player.x_dir = -1;
	wolf->player.x_plane = 0;
	wolf->player.y_plane = 0.66;
	wolf->player.turn_left = 0;
	wolf->player.turn_right = 0;
	wolf->player.forward = 0;
	wolf->player.backward = 0;
	wolf->player.turn_rate = 0.1;
	wolf->player.move_speed = 0.05;
}

void	ft_init(t_wolf *wolf)
{
	ft_init_map(wolf);
	ft_init_w(&wolf->win);
	ft_init_tex(wolf);
	ft_init_player(wolf);
	ft_frame(wolf);
}