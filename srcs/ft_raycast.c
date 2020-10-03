//
// Created by fenrir on 20/08/2020 16:22:04.
//

#include "../header/wolf.h"

/*
** map.x_step	=> map.check_x
** map.x		=> map.map_x
*/

void	ft_ray_init(t_wolf *wolf, int x)
{
	wolf->player.x_camera = 2 * x / (double)(wolf->win.res_x) - 1;
	wolf->ray.x_ray_position = wolf->player.x_pos;
	wolf->ray.y_ray_position = wolf->player.y_pos;
	wolf->ray.x_ray_direction = wolf->player.x_dir + wolf->player.x_plane * \
		wolf->player.x_camera;
	wolf->ray.y_ray_direction = wolf->player.y_dir + wolf->player.y_plane * \
		wolf->player.x_camera;
	wolf->map.map_x = (int)wolf->ray.x_ray_position;
	wolf->map.map_y = (int)wolf->ray.y_ray_position;
	ft_wall_detec_init(wolf);
	ft_wall_detec(wolf);
	if (wolf->frame.side == 0)
		wolf->frame.wall_distance = (wolf->map.map_x - wolf->ray.x_ray_position\
		+ (1 - wolf->map.check_x) / 2) / wolf->ray.x_ray_direction;
	else
		wolf->frame.wall_distance = (wolf->map.map_y - wolf->ray.y_ray_position\
		+ (1 - wolf->map.check_y) / 2) / wolf->ray.y_ray_direction;
}

void	ft_create_img(t_wolf *wolf)
{
	wolf->image.img = mlx_new_image(wolf->win.my_mlx, wolf->win.res_x,\
	wolf->win.res_y);
	wolf->image.data = mlx_get_data_addr(wolf->image.img, &wolf->image.bpp,\
		&wolf->image.sizeline, &wolf->image.endian);
}

void	ft_raycast(t_wolf *wolf)
{
	wolf->frame.x = -1;
	while (++wolf->frame.x < wolf->win.res_x)
	{
		ft_ray_init(wolf, wolf->frame.x);
		wolf->frame.line_height = (int)(wolf->win.res_y / wolf->frame.wall_distance);
		wolf->frame.draw_start = -wolf->frame.line_height / 2 + wolf->win.res_y / 2;
		if (wolf->frame.draw_start < 0)
			wolf->frame.draw_start = 0;
		wolf->frame.draw_end = wolf->frame.line_height / 2 + wolf->win.res_y / 2;
		if (wolf->frame.draw_end >= wolf->win.res_y)\
			wolf->frame.draw_end = wolf->win.res_y - 1;
		choose_texture(wolf);
		texture_calc(wolf);
		ft_draw(wolf->frame.x, wolf->frame.draw_start, wolf->frame.draw_end, wolf);
	}
}

void	ft_frame(t_wolf *wolf)
{
	ft_create_img(wolf);
	ft_raycast(wolf);
	mlx_put_image_to_window(wolf->win.my_mlx, wolf->win.win,\
		wolf->image.img, 0, 0);
}
