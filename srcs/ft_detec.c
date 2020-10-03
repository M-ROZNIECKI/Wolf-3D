//
// Created by fenrir on 20/08/2020 22:58:56.
//

#include "../header/wolf.h"

void	ft_wall_detec_init_y(t_wolf *wolf)
{
	wolf->ray.y_delta_distance = sqrt(1 + (wolf->ray.x_ray_direction *\
		wolf->ray.x_ray_direction) / (wolf->ray.y_ray_direction *\
		wolf->ray.y_ray_direction));
	if (wolf->ray.y_ray_direction < 0)
	{
		wolf->map.check_y = -1;
		wolf->ray.y_side_distance = (wolf->ray.y_ray_position -\
			wolf->map.map_y) * wolf->ray.y_delta_distance;
	}
	else
	{
		wolf->map.check_y = 1;
		wolf->ray.y_side_distance = (wolf->map.map_y + 1.0 -\
			wolf->ray.y_ray_position) * wolf->ray.y_delta_distance;
	}
}

void	ft_wall_detec_init(t_wolf *wolf)
{
	wolf->frame.item = 0;
	wolf->ray.x_delta_distance = sqrt(1 + (wolf->ray.y_ray_direction *\
		wolf->ray.y_ray_direction) / (wolf->ray.x_ray_direction *\
		wolf->ray.x_ray_direction));
	if (wolf->ray.x_ray_direction < 0)
	{
		wolf->map.check_x = -1;
		wolf->ray.x_side_distance = (wolf->ray.x_ray_position -\
			wolf->map.map_x) * wolf->ray.x_delta_distance;
	}
	else
	{
		wolf->map.check_x = 1;
		wolf->ray.x_side_distance = (wolf->map.map_x + 1.0 -\
			wolf->ray.x_ray_position) * wolf->ray.x_delta_distance;
	}
	ft_wall_detec_init_y(wolf);
}

void	ft_wall_detec(t_wolf *wolf)
{
	wolf->map.hit = 0;
	while (wolf->map.hit == 0)
	{
		if (wolf->ray.x_side_distance < wolf->ray.y_side_distance)
		{
			wolf->ray.x_side_distance += wolf->ray.x_delta_distance;
			wolf->map.map_x += wolf->map.check_x;
			wolf->frame.side = 0;
		}
		else
		{
			wolf->ray.y_side_distance += wolf->ray.y_delta_distance;
			wolf->map.map_y += wolf->map.check_y;
			wolf->frame.side = 1;
		}
		if (wolf->map.map[wolf->map.map_y][wolf->map.map_x] == '1')
			wolf->map.hit = 1;
/*		if (wolf->map.map[wolf->map.map_y][wolf->map.map_x] == '2')
			wolf->frame.item = 1;*/
	}
}
