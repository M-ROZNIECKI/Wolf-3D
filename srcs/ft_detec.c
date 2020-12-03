/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

static void	ft_wall_detec_init_y(t_wolf *wolf)
{
	wolf->ray.y_delta_dist = sqrt(1 + (wolf->ray.x_ray_dir *\
		wolf->ray.x_ray_dir) / (wolf->ray.y_ray_dir * wolf->ray.y_ray_dir));
	if (wolf->ray.y_ray_dir < 0)
	{
		wolf->map.check_y = -1;
		wolf->ray.y_side_dist = (wolf->ray.y_ray_pos -\
			wolf->map.map_y) * wolf->ray.y_delta_dist;
	}
	else
	{
		wolf->map.check_y = 1;
		wolf->ray.y_side_dist = (wolf->map.map_y + 1.0 -\
			wolf->ray.y_ray_pos) * wolf->ray.y_delta_dist;
	}
}

void		ft_wall_detec_init(t_wolf *wolf)
{
	wolf->frame.item = 0;
	wolf->ray.x_delta_dist = sqrt(1 + (wolf->ray.y_ray_dir *\
		wolf->ray.y_ray_dir) / (wolf->ray.x_ray_dir * wolf->ray.x_ray_dir));
	if (wolf->ray.x_ray_dir < 0)
	{
		wolf->map.check_x = -1;
		wolf->ray.x_side_dist = (wolf->ray.x_ray_pos - wolf->map.map_x) *\
		wolf->ray.x_delta_dist;
	}
	else
	{
		wolf->map.check_x = 1;
		wolf->ray.x_side_dist = (wolf->map.map_x + 1.0 -\
			wolf->ray.x_ray_pos) * wolf->ray.x_delta_dist;
	}
	ft_wall_detec_init_y(wolf);
}

static void	ft_ray_mov(t_wolf *wolf)
{
	if (wolf->ray.x_side_dist < wolf->ray.y_side_dist)
	{
		wolf->ray.x_side_dist += wolf->ray.x_delta_dist;
		wolf->map.map_x += wolf->map.check_x;
		wolf->frame.side = 0;
	}
	else
	{
		wolf->ray.y_side_dist += wolf->ray.y_delta_dist;
		wolf->map.map_y += wolf->map.check_y;
		wolf->frame.side = 1;
	}
}

static int	ft_add_sprite(t_wolf *wolf)
{
	t_lst	*new;

	if (wolf->frame.sprite == 0)
	{
		if (ft_add_sprite2(wolf) == 0)
			return (0);
	}
	else if (ft_check_list(wolf) == 1)
	{
		if (!(new = (t_lst *)malloc(sizeof(t_lst))))
			return (0);
		new->x = wolf->map.map_x + 0.5;
		new->y = wolf->map.map_y + 0.5;
		new->dist = pow(wolf->player.x_pos - new->x, 2) +\
		pow(wolf->player.y_pos - new->y, 2);
		ft_lst_add_frt(&wolf->spr, new);
	}
	return (1);
}

void		ft_wall_detec(t_wolf *wolf)
{
	wolf->map.hit = 0;
	while (wolf->map.hit == 0)
	{
		ft_ray_mov(wolf);
		if (wolf->map.map[wolf->map.map_y][wolf->map.map_x] == '1')
			wolf->map.hit = 1;
		if (wolf->map.map[wolf->map.map_y][wolf->map.map_x] == '3')
		{
			wolf->frame.item = 3;
			wolf->map.hit = 1;
		}
		if (wolf->map.map[wolf->map.map_y][wolf->map.map_x] == '2')
			if (ft_add_sprite(wolf) == 0)
			{
				ft_lst_clear(&wolf->spr, NULL);
				ft_free_sel(wolf, 3);
				ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
			}
	}
}
