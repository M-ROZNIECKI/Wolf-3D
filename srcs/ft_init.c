/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_init_w(t_win *win)
{
	win->my_mlx = mlx_init();
	mlx_get_screen_size(win->my_mlx, &win->res_x_max, &win->res_y_max);
	if (win->res_x > win->res_x_max)
		win->res_x = win->res_x_max;
	if (win->res_y > win->res_y_max)
		win->res_y = win->res_y_max;
	win->win = mlx_new_window(win->my_mlx, win->res_x, win->res_y, win->name);
}

void	ft_init_player(t_wolf *wolf)
{
	if (wolf->map.dir == 'N')
	{
		wolf->player.y_dir = -1;
		wolf->player.x_plane = 0.66;
	}
	else if (wolf->map.dir == 'S')
	{
		wolf->player.y_dir = 1;
		wolf->player.x_plane = -0.66;
	}
	else if (wolf->map.dir == 'E')
	{
		wolf->player.x_dir = 1;
		wolf->player.y_plane = 0.66;
	}
	else if (wolf->map.dir == 'W')
	{
		wolf->player.x_dir = -1;
		wolf->player.y_plane = -0.66;
	}
}

void	ft_init(t_wolf *wolf)
{
	wolf->frame.secret = 0;
	ft_init_map(wolf);
	if (wolf->ret == -1)
		if (ft_free_sel(wolf, 0))
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
	ft_init_w(&wolf->win);
	ft_init_tex(wolf);
	wolf->player.x_pos = wolf->map.start_x + 0.5;
	wolf->player.y_pos = wolf->map.start_y + 0.5;
	wolf->player.x_dir = 0;
	wolf->player.y_dir = 0;
	wolf->player.x_plane = 0;
	wolf->player.y_plane = 0;
	wolf->player.turn_left = 0;
	wolf->player.turn_right = 0;
	wolf->player.forward = 0;
	wolf->player.backward = 0;
	wolf->player.turn_rate = ROTATION_SPEED;
	wolf->player.move_speed = WALK_SPEED;
	ft_init_player(wolf);
	ft_frame(wolf);
}
