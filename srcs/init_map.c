/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:39:57 by mrozniec          #+#    #+#             */
/*   Updated: 2020/05/05 10:50:05 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

static int	ft_valid_map(t_map *map, int secret)
{
	map->temp_y = -1;
	map->temp_x = -1;
	while(++map->temp_y < map->map_y)
	{
		while(++map->temp_x < map->map_x)
			if (map->map[map->temp_y][map->temp_x] == '0' ||
			map->map[map->temp_y][map->temp_x] == '2' ||
			map->map[map->temp_y][map->temp_x] == '3' ||
			map->map[map->temp_y][map->temp_x] == 'N' ||
			map->map[map->temp_y][map->temp_x] == 'S' ||
			map->map[map->temp_y][map->temp_x] == 'E' ||
			map->map[map->temp_y][map->temp_x] == 'W')
			{
				if (secret == 0 && map->map[map->temp_y][map->temp_x] == '3')
					return (-1);
				if (ft_test_pos(map) == 1)
					return (-1);
			}
		map->temp_x = -1;
	}
	return (0);
}

static int	ft_fill_tab(t_map *map, int secret)
{
	unsigned int	i;
	t_lst		*temp;

	i = 0;
	temp = map->ch_map;
	if (!(map->map = ft_calloc(sizeof(char *), (map->map_y + 1))))
		return(-2);
	while (temp)
	{
		if (!(map->map[i] = ft_calloc(sizeof(char), (map->map_x + 1))))
		{
			ft_lst_clear(&map->ch_map, free);
			return (-2);
		}
		ft_strlcpy(map->map[i], temp->content, (ft_strlen(temp->content) + 1));
		temp = temp->next;
		i++;
	}
	ft_lst_clear(&map->ch_map, free);
	return (ft_valid_map(map, secret));
}

static int	ft_fill_map_bis(unsigned int temp, t_wolf *wolf)
{
	if (wolf->line[0] == '1' || wolf->line[0] == ' ')
	{
		ft_lst_add_back(&wolf->map.ch_map, ft_lst_new(ft_strdup(wolf->line)));
		wolf->map.map_y++;
		if ((temp = ft_strlen(wolf->line)) > wolf->map.map_x)
			wolf->map.map_x = temp;
	}
	else if (wolf->line[0] != '\0')
	{
		ft_lst_clear(&wolf->map.ch_map, free);
		return (-1);
	}
	else
	{
		ft_free(wolf->line);
		return (ft_fill_tab(&wolf->map, wolf->frame.secret));
	}
	ft_free(wolf->line);
	return (0);
}

static void	ft_fill_map(t_wolf *wolf)
{
	unsigned int	temp;
	int 			ret;

	wolf->map.ch_map = ft_lst_new(ft_strdup(wolf->line));
	wolf->map.map_y = 1;
	wolf->map.map_x = ft_strlen(wolf->line);
	ft_free(wolf->line);
	while ((get_next_line(wolf->fd, &wolf->line)) == 1)
		if ((ret = ft_fill_map_bis(temp, wolf)) <= -1)
		{
			ft_free_sel(wolf, 0);
			ft_error((char)ret, __LINE__, __FILE__, __FUNCTION__);
		}
	wolf->ok += 0x0100;
	if ((ret = ft_fill_tab(&wolf->map, wolf->frame.secret)) <= -1)
	{
		ft_free_sel(wolf, 0);
		ft_error((char)ret, __LINE__, __FILE__, __FUNCTION__);
	}
}

void		ft_init_map(t_wolf *wolf)
{
	while ((wolf->ret = get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if ((wolf->line[0] == '1' || wolf->line[0] == '0' ||
		wolf->line[0] == ' ') && wolf->ok == 0x0FF)
			ft_fill_map(wolf);
		else if (((wolf->line[0] == 'N' || wolf->line[0] == 'S' ||\
		wolf->line[0] == 'F' || wolf->line[0] == 'W' || wolf->line[0] == 'E' ||\
		wolf->line[0] == 'C') && wolf->ok < 0x0FF) || (wolf->line[0] == 'I' &&
		wolf->frame.secret == 0 && wolf->ok < 0x1FF))
			ft_texture(wolf);
		else if (wolf->line[0] == 'R' && wolf->ok < 0x0FF && (wolf->ok &\
		(unsigned)(0x080)) == 0)
			ft_fill_res(&wolf->win, wolf->line, &wolf->ok, wolf);
		else if (wolf->line[0] != '\0')
		{
			ft_free_sel(wolf, 0);
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		}
		ft_free(wolf->line);
	}
	ft_free(wolf->line);
}
