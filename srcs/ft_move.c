/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:22:17 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 16:22:17 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void		ft_right(t_player *player)
{
	if (player->turn_right == 1)
	{
		player->x_old_dir = player->x_dir;
		player->x_dir = player->x_dir * cos(player->turn_rate) -
			player->y_dir * sin(player->turn_rate);
		player->y_dir = player->x_old_dir * sin(player->turn_rate) +
			player->y_dir * cos(player->turn_rate);
		player->x_old_plane = player->x_plane;
		player->x_plane = player->x_plane * cos(player->turn_rate) -
			player->y_plane * sin(player->turn_rate);
		player->y_plane = player->x_old_plane * sin(player->turn_rate) +
			player->y_plane * cos(player->turn_rate);
	}
}

void		ft_left(t_player *player)
{
	if (player->turn_left == 1)
	{
		player->x_old_dir = player->x_dir;
		player->x_dir = player->x_dir * cos(-player->turn_rate) -
			player->y_dir * sin(-player->turn_rate);
		player->y_dir = player->x_old_dir * sin(-player->turn_rate) +
			player->y_dir * cos(-player->turn_rate);
		player->x_old_plane = player->x_plane;
		player->x_plane = player->x_plane * cos(-player->turn_rate) -
			player->y_plane * sin(-player->turn_rate);
		player->y_plane = player->x_old_plane * sin(-player->turn_rate) +
			player->y_plane * cos(-player->turn_rate);
	}
	ft_right(player);
}

void		ft_move_back(t_wolf *info)
{
	if (info->map.map[(int)(info->player.y_pos)][(int)(info->player.x_pos -
	info->player.x_dir * (info->player.move_speed + 0.2))] != '1')
		info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	if (info->map.map[(int)(info->player.y_pos - info->player.y_dir *
	(info->player.move_speed + 0.2))][(int)(info->player.x_pos)] != '1')
		info->player.y_pos -= info->player.y_dir * info->player.move_speed;
}

int			ft_move(t_wolf *wolf)
{
	if (wolf->player.forward == 1)
	{
		if (wolf->map.map[(int)(wolf->player.y_pos)][(int)(wolf->player.x_pos +
		wolf->player.x_dir * (wolf->player.move_speed + 0.2))] != '1')
			wolf->player.x_pos += wolf->player.x_dir * wolf->player.move_speed;
		if (wolf->map.map[(int)(wolf->player.y_pos + wolf->player.y_dir *
		(wolf->player.move_speed + 0.2))][(int)(wolf->player.x_pos)] != '1')
			wolf->player.y_pos += wolf->player.y_dir * wolf->player.move_speed;
	}
	if (wolf->player.backward == 1)
		ft_move_back(wolf);
	ft_left(&wolf->player);
	if ((wolf->player.forward || wolf->player.backward ||
		wolf->player.turn_right || wolf->player.turn_left) == 1)
	{
		mlx_destroy_image(wolf->win.my_mlx, wolf->image.img);
		ft_frame(wolf);
	}
	return (0);
}

int			ft_leave(t_wolf *wolf)
{
	int i;

	i = -1;
	mlx_destroy_image(wolf->win.my_mlx, wolf->image.img);
	while (wolf->map.map[++i])
		free(wolf->map.map[i]);
	i = 5;
	if (wolf->frame.secret == 1)
		i = 6;
	while (--i >= 0)
		mlx_destroy_image(wolf->win.my_mlx, wolf->sprite.wall[i].img);
	free(wolf->map.map);
	free(wolf->win.name);
	free(wolf->win.my_mlx);
	free(wolf);
	exit(0);
}
