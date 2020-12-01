//
// Created by fenrir on 30/11/2020.
//

#include "../header/wolf.h"

void 		ft_free(void *x)
{
	free(x);
	x = NULL;
}

static void ft_fre_sel_bis(t_wolf *wolf, int i)
{
	if (wolf->map.map)
	{
		while (wolf->map.map[++i])
			free(wolf->map.map[i]);
		free(wolf->map.map);
	}
	free(wolf->win.name);
	free(wolf);
}

static void	ft_free_spec(t_wolf *wolf, int i, int code)
{
	if (code == 3)
	{
		mlx_destroy_window(wolf->win.my_mlx, wolf->win.win);
		mlx_destroy_image(wolf->win.my_mlx, wolf->image.img);
	}
	i = 5 + wolf->frame.secret;
	while (--i >= 0)
		mlx_destroy_image(wolf->win.my_mlx, wolf->sprite.wall[i].img);
	free(wolf->win.my_mlx);
}

int 		ft_free_sel(t_wolf *wolf, int code)
{
	int i;

	i = -1;
	if (code == 0)
	{
		if (wolf->line)
			free(wolf->line);
		while (++i < (5 + wolf->frame.secret))
			if (wolf->sprite.wall[i].path)
				free(wolf->sprite.wall[i].path);
	}
	if (code >= 1)
		ft_free_spec(wolf, i, code);
	ft_fre_sel_bis(wolf, -1);
	return (1);
}

int 		ft_free_tex(t_wolf *wolf, int n)
{
	int i;

	mlx_destroy_window(wolf->win.my_mlx, wolf->win.win);
	i = n;
	while (--i >= 0)
		mlx_destroy_image(wolf->win.my_mlx, wolf->sprite.wall[i].img);
	n--;
	while (++n < (5 + wolf->frame.secret))
		if (wolf->sprite.wall[n].path)
			free(wolf->sprite.wall[n].path);
	free(wolf->win.my_mlx);
	ft_fre_sel_bis(wolf, -1);
	return (1);
}