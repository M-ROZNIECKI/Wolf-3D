/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:27:21 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/17 10:27:27 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

static void	ft_valid_map(t_map *map)
{
	map->temp_y = 0;
	map->temp_x = 0;
	while(map->temp_y < map->map_y - 1)
	{
		while (map->map[map->temp_y][map->temp_x] == '1')
			map->temp_x++;
		if (map->map[map->temp_y][map->temp_x] != '\0' || map->map[map->temp_y][0] != '1')
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		while (map->map[map->temp_y + 1][map->temp_x] == '\0')
		{
			map->temp_x--;
			if (map->map[map->temp_y][map->temp_x] != '\0' && map->map[map->temp_y][map->temp_x] != '1')
				ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		}
		if (map->map[map->temp_y + 1][map->temp_x] != '1' || map->map[map->temp_y + 1][0] != '1')
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		map->temp_y++;
	}
	while (map->temp_x > 0)
		if (map->map[map->temp_y][map->temp_x--] != '1')
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
}

static void	ft_del_space(t_map *map)
{
	t_lst_map	*temp;
	int			i[3];

	temp = map->ch_map;
	i[1] = 0;
	while (temp)
	{
		i[0] = 0;
		while (temp->content[i[0]])
		{
			i[2] = 0;
			while ((temp->content[i[0] + i[2]] >= 9 &&
					temp->content[i[0] + i[2]] <= 13) ||
					temp->content[i[0] + i[2]] == 32)
				i[2]++;
			if (i[2] > 0)
				ft_strlcpy(&temp->content[i[0]],
						&temp->content[i[0] + i[2]], map->map_x);
			i[0]++;
		}
		if (i[0] > i[1])
			i[1] = i[0];
		temp = temp->next;
	}
	map->map_x = i[1];
}

static void	ft_fill_tab(t_map *map)
{
	unsigned int	i;
	t_lst_map		*temp;

	i = 0;
	temp = map->ch_map;
	if (!(map->map = ft_calloc(sizeof(char *), (map->map_y + 1))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	while (temp)
	{
		if (!(map->map[i] = ft_calloc(sizeof(char), (map->map_x + 1))))
			ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
		ft_strlcpy(map->map[i], temp->content, (ft_strlen(temp->content) + 1));
		temp = temp->next;
		i++;
	}
	ft_valid_map(map);
}

static void	ft_fill_map(t_wolf *wolf)
{
	unsigned int	temp;

	wolf->map.ch_map = ft_lstnew(ft_strdup(wolf->line));
	wolf->map.map_y = 1;
	wolf->map.map_x = ft_strlen(wolf->line);
	while ((get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if (wolf->line[0] == '1' || wolf->line[0] == '0')
		{
			ft_lstadd_back(&wolf->map.ch_map, ft_lstnew(ft_strdup(wolf->line)));
			wolf->map.map_y++;
			if ((temp = ft_strlen(wolf->line)) > wolf->map.map_x)
				wolf->map.map_x = temp;
		}
		else if (wolf->line[0] != '\0')
		{
			free(wolf->line);
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		}
		else
		{
			free(wolf->line);
			ft_del_space(&wolf->map);
			ft_fill_tab(&wolf->map);
			return;
		}
		free(wolf->line);
	}
	wolf->ok += 0x0100;
	ft_del_space(&wolf->map);
	ft_fill_tab(&wolf->map);
}

void		ft_init_map(t_wolf *wolf)
{
	while ((wolf->ret = get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if ((wolf->line[0] == '1' || wolf->line[0] == '0') && wolf->ok == 0x0FF)
			ft_fill_map(wolf);
		else if ((wolf->line[0] == 'N' || wolf->line[0] == 'S' ||
				wolf->line[0] == 'F' || wolf->line[0] == 'W' ||
				wolf->line[0] == 'E' || wolf->line[0] == 'C') && wolf->ok < 0x0FF)
			ft_texture(wolf);
		else if (wolf->line[0] == 'R' && wolf->ok < 0x0FF && (wolf->ok & (unsigned)0x080) == 0)
			ft_fill_res(&wolf->win, &wolf->line[1], &wolf->ok);
		else if (wolf->line[0] != '\0')
		{
			free(wolf->line);
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		}
		if (wolf->ok != 0xFF)
			free(wolf->line);
	}
	if (wolf->ret == -1)
		ft_error(-1, __LINE__, __FILE__, __FUNCTION__);
}
