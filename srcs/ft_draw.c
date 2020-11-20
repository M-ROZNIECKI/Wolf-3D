/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:54:43 by fenrir            #+#    #+#             */
/*   Updated: 2020/11/20 14:55:07 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"


void	ft_draw3(int x, int draw_start, t_wolf *wolf)
{
	int		tex_y;

	tex_y = wolf->tex_y;

	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start] =\
	(char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
	* 4 + 4 * wolf->sprite.wall[wolf->sel].x * tex_y];
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start + 1] =\
	(char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
	* 4 + 4 * wolf->sprite.wall[wolf->sel].x * tex_y + 1];
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start + 2] =\
	(char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
	* 4 + 4 * wolf->sprite.wall[wolf->sel].x * tex_y + 2];
	wolf->image.data[x * 4 + 4 * wolf->win.res_x * draw_start + 3] = 0;
}

void	ft_draw2(int x, int draw_start, t_wolf *wolf)
{
	wolf->d = draw_start * 256 - wolf->win.res_y * 128 +\
	wolf->frame.line_height * 128;
	wolf->tex_y = (int)((((long int)(wolf->d) *\
	(long int)(wolf->sprite.wall[wolf->sel].y)) /\
	(long int)(wolf->frame.line_height)) / (long int)(256));
	if (\
	((char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
    * 4 + 4 * wolf->sprite.wall[wolf->sel].x * wolf->tex_y + 2] != 0) ||\
    ((char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
    * 4 + 4 * wolf->sprite.wall[wolf->sel].x * wolf->tex_y + 1] != 0) ||\
    ((char)wolf->sprite.wall[wolf->sel].data[wolf->sprite.wall[wolf->sel].tex_x\
    * 4 + 4 * wolf->sprite.wall[wolf->sel].x * wolf->tex_y] != 0))
		ft_draw3(x, draw_start, wolf);
}

static void ft_drw_c_f(int x, int y, t_wolf *wolf)
{
	while (++y <= wolf->win.res_y / 2)
	{
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y] = wolf->sprite.c[2];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 1] =\
			wolf->sprite.c[1];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 2] =\
			wolf->sprite.c[0];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 3] = 0;
	}
	y--;
	while (++y < wolf->win.res_y)
	{
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y] = wolf->sprite.f[2];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 1] =\
			wolf->sprite.f[1];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 2] =\
			wolf->sprite.f[0];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 3] = 0;
	}
}

void	ft_draw(int x, int draw_start, int draw_end, t_wolf *wolf)
{
	int		y;

	y = -1;
	ft_drw_c_f(x, y, wolf);
	while (++draw_start <= draw_end)
		ft_draw2(x, draw_start, wolf);
}
