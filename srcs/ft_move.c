//
// Created by fenrir on 01/09/2020 01:19:32.
//

#include "../header/wolf.h"

static void	ft_right(t_wolf *wolf)
{
	if (wolf->player.turn_right == 1)
	{
		wolf->player.x_old_dir = wolf->player.x_dir;
		wolf->player.x_dir = wolf->player.x_dir * cos(-wolf->player.turn_rate)
			- wolf->player.y_dir * sin(-wolf->player.turn_rate);
		wolf->player.y_dir = wolf->player.x_old_dir *
			sin(-wolf->player.turn_rate) + wolf->player.y_dir *
			cos(-wolf->player.turn_rate);
		wolf->player.x_old_plane = wolf->player.x_plane;
		wolf->player.x_plane = wolf->player.x_plane *
			cos(-wolf->player.turn_rate) - wolf->player.y_plane *
			sin(-wolf->player.turn_rate);
		wolf->player.y_plane = wolf->player.x_old_plane *
			sin(-wolf->player.turn_rate) + wolf->player.y_plane *
			cos(-wolf->player.turn_rate);
	}
}

static void	ft_left(t_wolf *wolf)
{
	if (wolf->player.turn_left == 1)
	{
		wolf->player.x_old_dir = wolf->player.x_dir;
		wolf->player.x_dir = wolf->player.x_dir * cos(wolf->player.turn_rate)
			- wolf->player.y_dir * sin(wolf->player.turn_rate);
		wolf->player.y_dir = wolf->player.x_old_dir *
			sin(wolf->player.turn_rate) + wolf->player.y_dir *
			cos(wolf->player.turn_rate);
		wolf->player.x_old_plane = wolf->player.x_plane;
		wolf->player.x_plane = wolf->player.x_plane *
			cos(wolf->player.turn_rate) - wolf->player.y_plane *
			sin(wolf->player.turn_rate);
		wolf->player.y_plane = wolf->player.x_old_plane *
			sin(wolf->player.turn_rate) + wolf->player.y_plane *
			cos(wolf->player.turn_rate);
	}
	ft_right(wolf);
}

static void	ft_move_back(t_wolf *info)
{
	if (info->map.map[(int)(info->player.x_pos - info->player.x_dir
		* info->player.move_speed)][(int)(info->player.y_pos)] != '1')
		info->player.x_pos -= info->player.x_dir * info->player.move_speed;
	if (info->map.map[(int)(info->player.x_pos)][(int)(info->player.y_pos
		- info->player.y_dir * info->player.move_speed)] != '1')
		info->player.y_pos -= info->player.y_dir * info->player.move_speed;
}

int			ft_move(t_wolf *wolf)
{
	if (wolf->player.forward == 1)
	{
		if (wolf->map.map[(int)(wolf->player.x_pos + wolf->player.x_dir
		* wolf->player.move_speed)][(int)(wolf->player.y_pos)] != '1')
			wolf->player.x_pos += wolf->player.x_dir * wolf->player.move_speed;
		if (wolf->map.map[(int)(wolf->player.x_pos)][(int)(wolf->player.y_pos
		+ wolf->player.y_dir * wolf->player.move_speed)] != '1')
			wolf->player.y_pos += wolf->player.y_dir * wolf->player.move_speed;
	}
	if (wolf->player.backward == 1)
		ft_move_back(wolf);
	ft_left(wolf);
	if ((wolf->player.forward || wolf->player.backward ||
		 wolf->player.turn_right || wolf->player.turn_left) == 1)
		ft_frame(wolf);
	return (0);
}

//add free malloc and struct
int 		ft_leave(t_wolf *wolf)
{
	exit(0);
}
