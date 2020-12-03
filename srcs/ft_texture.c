/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:21:57 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:21:57 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

static void	ft_copy_path(char **fill, char *entry)
{
	int i;

	i = 0;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	*fill = ft_strdup(&entry[i]);
}

static void	ft_fill_color(char color[3], char *entry)
{
	int i;

	i = 0;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	color[0] = (char)ft_atoi(&entry[i]);
	while (entry[i] && entry[i] != ',')
		i++;
	i++;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	color[1] = (char)ft_atoi(&entry[i]);
	while (entry[i] && entry[i] != ',')
		i++;
	i++;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	color[2] = (char)ft_atoi(&entry[i]);
}

static void	ft_texture2(t_wolf *wolf)
{
	if (wolf->line[0] == 'E' && (wolf->ok & (unsigned)0x010) == 0)
	{
		ft_copy_path(&wolf->sprite.wall[2].path, &wolf->line[2]);
		wolf->ok += 0x010;
	}
	else if (wolf->line[0] == 'F' && (wolf->ok & (unsigned)0x020) == 0)
	{
		ft_fill_color(wolf->sprite.f, &wolf->line[1]);
		wolf->ok += 0x020;
	}
	else if (wolf->line[0] == 'C' && (wolf->ok & (unsigned)0x040) == 0)
	{
		ft_fill_color(wolf->sprite.c, &wolf->line[1]);
		wolf->ok += 0x040;
	}
	else if (wolf->line[0] == 'I' && wolf->frame.secret == 0)
	{
		ft_copy_path(&wolf->sprite.wall[5].path, &wolf->line[1]);
		wolf->frame.secret = 1;
	}
	else
		ft_error(0, __LINE__, __FILE__, __FUNCTION__);
}

void		ft_texture(t_wolf *wolf)
{
	if (wolf->line[0] == 'S' && wolf->line[1] == 'O' && (wolf->ok & 0x01) == 0)
	{
		ft_copy_path(&wolf->sprite.wall[1].path, &wolf->line[2]);
		wolf->ok += 0x01;
	}
	else if (wolf->line[0] == 'S' && (wolf->ok & (unsigned)0x02) == 0)
	{
		ft_copy_path(&wolf->sprite.wall[4].path, &wolf->line[1]);
		wolf->ok += 0x02;
	}
	else if (wolf->line[0] == 'N' && (wolf->ok & (unsigned)0x04) == 0)
	{
		ft_copy_path(&wolf->sprite.wall[0].path, &wolf->line[2]);
		wolf->ok += 0x04;
	}
	else if (wolf->line[0] == 'W' && (wolf->ok & (unsigned)0x08) == 0)
	{
		ft_copy_path(&wolf->sprite.wall[3].path, &wolf->line[2]);
		wolf->ok += 0x08;
	}
	else
		ft_texture2(wolf);
}

void		ft_fill_res(t_win *win, char *entry, unsigned short *ok,\
t_wolf *wolf)
{
	int i;

	i = 1;
	*ok += 0x080;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	win->res_x = ft_atoi(&entry[i]);
	while (((entry[i] >= 13 && entry[i] != 32) || entry[i] <= 9) && entry[i])
		i++;
	win->res_y = ft_atoi(&entry[i]);
	if (win->res_y < 0 || win->res_x < 0)
	{
		ft_free_sel(wolf, 0);
		ft_error(1, __LINE__, __FILE__, __FUNCTION__);
	}
}
