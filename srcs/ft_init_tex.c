/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 21:37:45 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_init_tex(t_wolf *wolf)
{
	int n;
	int x;

	x = 5;
	n = -1;
	if (wolf->frame.secret == 1)
		x = 6;
	while (++n < x)
	{
		if (0 == ft_strncmp(&wolf->sprite.wall[n].path[ft_strlen(\
			wolf->sprite.wall[n].path) - 3], "xpm", 3))
		{
			if ((wolf->sprite.wall[n].img = mlx_xpm_file_to_image(wolf->win.my_mlx, \
			wolf->sprite.wall[n].path, &wolf->sprite.wall[n].x, \
			&wolf->sprite.wall[n].y)) == (void *)0)
				ft_error(2, __LINE__, __FILE__, __FUNCTION__);
		}
		else if (ft_free_tex(wolf, n))
			ft_error(2, __LINE__, __FILE__, __FUNCTION__);
		wolf->sprite.wall[n].data = mlx_get_data_addr(wolf->sprite.wall[n].img,\
		&wolf->sprite.wall[n].bpp, &wolf->sprite.wall[n].sizeline, \
		&wolf->sprite.wall[n].endian);
		ft_free(wolf->sprite.wall[n].path);
	}
}

void	choose_texture(t_wolf *wolf)
{
	if (wolf->frame.side == 0 && wolf->ray.x_ray_dir > 0)
		wolf->sel = 2;
	else if (wolf->frame.side == 0 && wolf->ray.x_ray_dir < 0)
		wolf->sel = 3;
	else if (wolf->frame.side == 1 && wolf->ray.y_ray_dir > 0)
		wolf->sel = 1;
	else
		wolf->sel = 0;
	if (wolf->frame.item == 3)
		wolf->sel = 5;
}

void	texture_calc(t_wolf *wolf)
{
	if (wolf->frame.side == 0)
		wolf->frame.ux = wolf->player.y_pos + \
		wolf->frame.wall_dist * wolf->ray.y_ray_dir;
	else
		wolf->frame.ux = wolf->player.x_pos + \
		wolf->frame.wall_dist * wolf->ray.x_ray_dir;
	wolf->frame.ux -= floor((wolf->frame.ux));
	wolf->sprite.wall[wolf->sel].tex_x = (int)(wolf->frame.ux * \
	(double)wolf->sprite.wall[wolf->sel].x);
	if (wolf->frame.side == 0 && wolf->ray.x_ray_dir > 0)
		wolf->sprite.wall[wolf->sel].tex_x = wolf->sprite.wall[wolf->sel].x -\
		wolf->sprite.wall[wolf->sel].tex_x - 1;
	if (wolf->frame.side == 1 && wolf->ray.y_ray_dir < 0)
		wolf->sprite.wall[wolf->sel].tex_x = wolf->sprite.wall[wolf->sel].x -\
		wolf->sprite.wall[wolf->sel].tex_x - 1;
}
