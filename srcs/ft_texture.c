/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:01:30 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/17 14:01:35 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

static void	ft_copy_path(char *fill, char *entry)
{
	int i;

	i = 0;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	fill = ft_strdup(&entry[i]);
}

static void	ft_fill_color(unsigned char color[3], char *entry)
{
	int i;

	i = 0;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	color[0] = ft_atoi(&entry[i]);
	while (entry[i] && entry[i] != ',')
		i++;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	color[1] = ft_atoi(&entry[i]);
	while (entry[i] && entry[i] != ',')
		i++;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	color[2] = ft_atoi(&entry[i]);
}

static void	ft_texture2(t_wolf *wolf)
{
	if (wolf->line[0] == 'E' && (wolf->ok & 0x010) == 0)
	{
		ft_copy_path(wolf->sprite.ea, &wolf->line[2]);
		wolf->ok += 0x010;
	}
	else if (wolf->line[0] == 'F' && (wolf->ok & 0x020) == 0)
	{
		ft_fill_color(wolf->sprite.f, &wolf->line[1]);
		wolf->ok += 0x020;
	}
	else if (wolf->line[0] == 'C' && (wolf->ok & 0x040) == 0)
	{
		ft_fill_color(wolf->sprite.c, &wolf->line[1]);
		wolf->ok += 0x040;
	}
	else
		ft_error(0, __LINE__, __FILE__, __FUNCTION__);
}

void		ft_texture(t_wolf *wolf)
{
	if (wolf->line[0] == 'S' && wolf->line[1] == 'O' && (wolf->ok & 0x01) == 0)
	{
		ft_copy_path(wolf->sprite.so, &wolf->line[2]);
		wolf->ok += 0x01;
	}
	else if (wolf->line[0] == 'S' && (wolf->ok & 0x02) == 0)
	{
		ft_copy_path(wolf->sprite.s, &wolf->line[1]);
		wolf->ok += 0x02;
	}
	else if (wolf->line[0] == 'N' && (wolf->ok & 0x04) == 0)
	{
		ft_copy_path(wolf->sprite.no, &wolf->line[2]);
		wolf->ok += 0x04;
	}
	else if (wolf->line[0] == 'W' && (wolf->ok & 0x08) == 0)
	{
		ft_copy_path(wolf->sprite.we, &wolf->line[2]);
		wolf->ok += 0x08;
	}
	else
		ft_texture2(wolf);
}

void		ft_fill_res(t_win *win, char *entry, unsigned char *ok)
{
	int i;

	i = 0;

	*ok += 0x080;
	while ((entry[i] >= 9 && entry[i] <= 13) || entry[i] == 32)
		i++;
	win->res_x = ft_atoi(&entry[i]);
	while (((entry[i] >= 13 && entry[i] != 32) || entry[i] <= 9) && entry[i])
		i++;
	win->res_y = ft_atoi(&entry[i]);
}
