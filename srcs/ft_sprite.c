/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:57:30 by fenrir            #+#    #+#             */
/*   Updated: 2020/11/20 14:58:05 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_sort_lst(t_wolf *wolf)
{
	t_lst			*tmp;
	double			x;

	tmp = wolf->spr;
	while (tmp->next)
	{
		if (tmp->dist < tmp->next->dist)
		{
			x = tmp->x;
			tmp->x = tmp->next->x;
			tmp->next->x = x;
			x = tmp->y;
			tmp->y = tmp->next->y;
			tmp->next->y = x;
			x = tmp->dist;
			tmp->dist = tmp->next->dist;
			tmp->next->dist = x;
			tmp = wolf->spr;
		}
		else
			tmp = tmp->next;
	}
}

void	ft_spr_drw(t_wolf *wolf, const double *wall_dist_buf, int stripe)
{
	int	y;

	y = wolf->spr_data.drw_start_y - 1;
	if (wolf->spr_data.trs_y < wall_dist_buf[stripe] && stripe < \
	wolf->win.res_x && stripe > 0 && wolf->spr_data.trs_y > 0)
		while(++y < wolf->spr_data.drw_end_y)
		{
			wolf->d = (y - wolf->mov_dwn) * 256 - wolf->win.res_y * 128 +\
			wolf->spr_data.spr_h * 128;
			wolf->tex_y = (int)((((long int)(wolf->d) *\
			(long int)(wolf->sprite.wall[wolf->sel].y)) /\
			(long int)(wolf->spr_data.spr_h)) / 256);
			if (wolf->tex_y >= 0)
				if (\
	((char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
    * 4 + 4 * wolf->sprite.wall[wolf->sel].x * wolf->tex_y + 2] != 0) ||\
    ((char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
    * 4 + 4 * wolf->sprite.wall[wolf->sel].x * wolf->tex_y + 1] != 0) ||\
    ((char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
    * 4 + 4 * wolf->sprite.wall[wolf->sel].x * wolf->tex_y] != 0))
					ft_draw3(stripe, y, wolf);
		}
}

void	ft_spr_calc_2(t_wolf *wolf, double *wall_dist_buf)
{
	int	stripe;

	if (wolf->spr_data.drw_end_y >= wolf->win.res_y)
		wolf->spr_data.drw_end_y = wolf->win.res_y - 1;
	wolf->spr_data.spr_w = abs((int)(wolf->win.res_y / wolf->spr_data.trs_y)) *\
	SPRITE_SIZE;
	wolf->spr_data.drw_start_x = wolf->spr_data.spr_scr_x -\
	wolf->spr_data.spr_w / 2;
	wolf->spr_data.drw_end_x = wolf->spr_data.spr_scr_x +\
	wolf->spr_data.spr_w / 2;
	if (wolf->spr_data.drw_end_x >= wolf->win.res_x)
		wolf->spr_data.drw_end_x = wolf->win.res_x - 1;
	stripe = wolf->spr_data.drw_start_x - 1;
	if (stripe < -1)
		stripe = -1;
	while (++stripe < wolf->spr_data.drw_end_x)
	{
		wolf->sprite.wall[wolf->sel].tex_x = (int)(256 * (stripe -\
		wolf->spr_data.drw_start_x) * (double)wolf->sprite.wall[wolf->sel].x /\
		wolf->spr_data.spr_w) / 256;
		ft_spr_drw(wolf, wall_dist_buf, stripe);
	}
}

void	ft_spr_calc(t_wolf *wolf, t_lst *spr, double *wall_dist_buf)
{
	wolf->spr_data.x = spr->x - wolf->player.x_pos;
	wolf->spr_data.y = spr->y - wolf->player.y_pos;
	wolf->spr_data.inv = 1 / (wolf->player.x_plane * wolf->player.y_dir\
	- wolf->player.y_plane * wolf->player.x_dir);
	wolf->spr_data.trs_x = wolf->spr_data.inv * (wolf->player.y_dir\
	* wolf->spr_data.x -\
	wolf->player.x_dir * wolf->spr_data.y);
	wolf->spr_data.trs_y = wolf->spr_data.inv * (wolf->player.x_plane\
	* wolf->spr_data.y - wolf->player.y_plane * wolf->spr_data.x);
	wolf->mov_dwn = (int)(wolf->win.res_y * (1 - SPRITE_SIZE) / (2 *\
	wolf->spr_data.trs_y));
	wolf->spr_data.spr_scr_x = (int)((wolf->win.res_x / 2) * (1 +\
	wolf->spr_data.trs_x / wolf->spr_data.trs_y));
	wolf->spr_data.spr_h = abs((int)(wolf->win.res_y /\
	wolf->spr_data.trs_y)) * SPRITE_SIZE;
	wolf->spr_data.drw_start_y = (wolf->win.res_y - wolf->spr_data.spr_h) / 2\
	 + wolf->mov_dwn;
	if (wolf->spr_data.drw_start_y < 0)
		wolf->spr_data.drw_start_y = 0;
    wolf->spr_data.drw_end_y = (wolf->win.res_y + wolf->spr_data.spr_h) / 2\
    + wolf->mov_dwn;
    ft_spr_calc_2(wolf, wall_dist_buf);
}

void	ft_sprite(t_wolf *wolf, double *wall_dist_buf)
{
	t_lst	*spr;

	wolf->sel = 4;
	ft_sort_lst(wolf);
	spr = wolf->spr;
	while(spr)
	{
		ft_spr_calc(wolf, spr, wall_dist_buf);
		spr = spr->next;
	}
	ft_lst_clear(&wolf->spr, NULL);
}
