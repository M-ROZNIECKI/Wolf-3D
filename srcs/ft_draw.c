//
// Created by fenrir on 20/08/2020 18:54:43.
//

#include "../header/wolf.h"

void	ft_draw2(int x, int draw_start, t_wolf *wolf)
{
	int		d;
	int		tex_y;

	d = draw_start * 256 - wolf->win.res_y * 128 + wolf->frame.line_height *\
	128;
	tex_y = ((d * wolf->sprite.wall[wolf->sel].y) / wolf->frame.line_height)\
	/ 256;
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

void	ft_draw(int x, int draw_start, int draw_end, t_wolf *wolf)
{
	int		y;

	y = -1;
	while (++y <= draw_start)
	{
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y] = wolf->sprite.c[2];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 1] =\
			wolf->sprite.c[1];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 2] =\
			wolf->sprite.c[0];
		wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 3] = 0;
	}
	while (++draw_start <= draw_end)
		ft_draw2(x, draw_start, wolf);
	y = draw_start - 5;
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
