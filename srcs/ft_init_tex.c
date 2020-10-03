/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:15:49 by fenrir            #+#    #+#             */
/*   Updated: 2020/03/12 15:15:10 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"
/*
 * 0:NORTH
 * 1:SOUTH
 * 2:EAST
 */
void	ft_init_tex(t_wolf *wolf)
{
	int n;
	n = -1;
	while(++n < 5)
	{
		if (0 == ft_strncmp(&wolf->sprite.wall[n].path[ft_strlen(\
			wolf->sprite.wall[n].path) - 3], "xpm", 3))
			wolf->sprite.wall[n].img = mlx_xpm_file_to_image(wolf->win.my_mlx, \
			wolf->sprite.wall[n].path, &wolf->sprite.wall[n].x, \
			&wolf->sprite.wall[n].y);
		else
			ft_error(2, __LINE__, __FILE__, __FUNCTION__);
		wolf->sprite.wall[n].data = mlx_get_data_addr(wolf->sprite.wall[n].img,\
			&wolf->sprite.wall[n].bpp, &wolf->sprite.wall[n].sizeline, \
			&wolf->sprite.wall[n].endian);
	}
}

void	choose_texture(t_wolf *wolf)
{
	if (wolf->frame.side == 0 && wolf->ray.x_ray_direction > 0)
		wolf->sel = 2;
	else if (wolf->frame.side == 0 && wolf->ray.x_ray_direction < 0)
		wolf->sel = 3;
	else if (wolf->frame.side == 1 && wolf->ray.y_ray_direction > 0)
		wolf->sel = 1;
	else
		wolf->sel = 0;
	if (wolf->frame.item == 1)
		wolf->sel = 4;
}

void	texture_calc(t_wolf *wolf)
{
	if (wolf->frame.side == 0)
		wolf->frame.ux = wolf->player.y_pos + \
		wolf->frame.wall_distance * wolf->ray.y_ray_direction;
	else
		wolf->frame.ux = wolf->player.x_pos + \
		wolf->frame.wall_distance * wolf->ray.x_ray_direction;
	wolf->frame.ux -= floor((wolf->frame.ux));
	wolf->sprite.wall[wolf->sel].tex_x = (int)(wolf->frame.ux * \
	(double)wolf->sprite.wall[wolf->sel].x);
	if (wolf->frame.side == 0 && wolf->ray.x_ray_direction > 0)
		wolf->sprite.wall[wolf->sel].tex_x = wolf->sprite.wall[wolf->sel].x -\
		wolf->sprite.wall[wolf->sel].tex_x - 1;
	if (wolf->frame.side == 1 && wolf->ray.y_ray_direction < 0)
		wolf->sprite.wall[wolf->sel].tex_x = wolf->sprite.wall[wolf->sel].x -\
		wolf->sprite.wall[wolf->sel].tex_x - 1;
}
