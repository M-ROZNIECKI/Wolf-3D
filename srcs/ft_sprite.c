//
// Created by fenrir on 30/10/2020. 16:57:30
//

#include "../header/wolf.h"

void	ft_sort_lst(t_wolf *wolf)
{
	t_lst			*tmp;
	double			x;
	double			y;

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
			y = tmp->dist;
			tmp->dist = tmp->next->dist;
			tmp->next->dist = y;
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
			wolf->d = y * 256 - wolf->win.res_y * 128 + wolf->spr_data.spr_h *\
			128;
			wolf->tex_y = ((wolf->d * wolf->sprite.wall[wolf->sel].y) /\
			wolf->spr_data.spr_h) / 256;
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

	wolf->spr_data.drw_end_y = (wolf->win.res_y + wolf->spr_data.spr_h) / 2;
	if (wolf->spr_data.drw_end_y >= wolf->win.res_y)
		wolf->spr_data.drw_end_y = wolf->win.res_y - 1;
	wolf->spr_data.spr_w = abs((int)(wolf->win.res_y / wolf->spr_data.trs_y));
	wolf->spr_data.drw_start_x = wolf->spr_data.spr_scr_x -\
	wolf->spr_data.spr_w / 2;
//	if (wolf->spr_data.drw_start_x < 0)
//		wolf->spr_data.drw_start_x = 0;
	wolf->spr_data.drw_end_x = wolf->spr_data.spr_scr_x +\
	wolf->spr_data.spr_w / 2;
	if (wolf->spr_data.drw_end_x >= wolf->win.res_x)
		wolf->spr_data.drw_end_x = wolf->win.res_x - 1;

	stripe = wolf->spr_data.drw_start_x - 1;
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
	wolf->spr_data.spr_scr_x = (int)((wolf->win.res_x / 2) * (1 +\
	wolf->spr_data.trs_x / wolf->spr_data.trs_y));
	wolf->spr_data.spr_h = abs((int)(wolf->win.res_y /\
	wolf->spr_data.trs_y));
	wolf->spr_data.drw_start_y = (wolf->win.res_y - wolf->spr_data.spr_h) / 2;
	if (wolf->spr_data.drw_start_y < 0)
		wolf->spr_data.drw_start_y = 0;
	ft_spr_calc_2(wolf, wall_dist_buf);
}

void	ft_sprite(t_wolf *wolf, double *wall_dist_buf)
{
	t_lst	*spr;

	wolf->sel = 4;
	ft_sort_lst(wolf);
	//ft_printf("spr x =%lf y =%lf ?\n", wolf->spr->x, wolf->spr->y);
	spr = wolf->spr;
	while(spr)
	{
		ft_spr_calc(wolf, spr, wall_dist_buf);
		spr = spr->next;
	}
	ft_lst_clear(&wolf->spr, NULL);
}

































































































/*
void ft_nothing(void *content)
{
	content = "\0";
}

void ft_draw3(int x, int draw_start, t_wolf *wolf, int tex_y)
{
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start] =\
	(char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
	* 4 + 4 * wolf->sprite.wall[wolf->sel].x * tex_y];
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start + 1] =\
	(char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
	* 4 + 4 * wolf->sprite.wall[wolf->sel].x * tex_y + 1];
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start + 2] =\
	(char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
	* 4 + 4 * wolf->sprite.wall[wolf->sel].x * tex_y + 2];
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start + 3] = (char)0;
}

void	ft_draw_sprite(t_wolf *wolf, double dist)
{*/
	/*ft_printf("\n\nKurva = %lf\nCyka = %d\n\n", dist,\
	wolf->frame.draw_end);*/
/*	wolf->frame.line_height = (int)(wolf->win.res_y / dist * SPRITE_SIZE);
	wolf->frame.draw_start = (int)((wolf->win.res_y - wolf->frame.line_height)\
	/ 2);
	if (wolf->frame.draw_start < 0)
		wolf->frame.draw_start = 0;
	wolf->frame.draw_end = ((wolf->frame.line_height + wolf->win.res_y) / 2);
	if (wolf->frame.draw_end >= wolf->win.res_y)
		wolf->frame.draw_end = wolf->win.res_y - 1;

	wolf->frame.wall_dist = dist;
	texture_calc(wolf);

	while (++wolf->frame.draw_start <= wolf->frame.draw_end)
		ft_draw2(wolf->frame.x, wolf->frame.draw_start, wolf);
}

void	ft_sprite(t_wolf *wolf)
{
	t_lst *temp;
	double tan_angle;
	double a;
	double b;

	if (wolf->frame.sprite == 2)
	{
		temp = wolf->spr;
		wolf->sel = 4;
		while (temp) {
//			ft_printf("\nhello x=%d, y=%d\n", temp->x, temp->y);
			tan_angle = tan(atan((temp->y - wolf->player.y_pos) /\
            (temp->x - wolf->player.x_pos)) +\
            atan(wolf->ray.y_delta_dist / wolf->ray.x_delta_dist));
			b = sqrt(pow(temp->y - wolf->player.y_pos, 2)\
 				+ pow(temp->x - wolf->player.x_pos, 2));
			a = tan_angle * b;
		//	if (a <= SPRITE_SIZE)
				ft_draw_sprite(wolf, b);
			temp = temp->next;
		}
		ft_printf("\nconnard A = %lf, b =%lf, a =%lf\n", atan(tan_angle), b, a);
		ft_lst_clear(&wolf->spr, ft_nothing);
	}
}*/