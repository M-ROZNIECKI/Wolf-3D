/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:33:51 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/27 17:33:51 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_start_pos(t_map *map)
{
	map->temp_y = 0;
	map->temp_x = 0;
	while (map->temp_y < map->map_y &&
		   map->map[map->temp_y][map->temp_x] != 'N' &&
		   map->map[map->temp_y][map->temp_x] != 'S' &&
		   map->map[map->temp_y][map->temp_x] != 'E' &&
		   map->map[map->temp_y][map->temp_x] != 'W')
	{
		map->temp_x = 0;
		while (map->map[map->temp_y][map->temp_x] &&
			   map->map[map->temp_y][map->temp_x] != 'N' &&
			   map->map[map->temp_y][map->temp_x] != 'S' &&
			   map->map[map->temp_y][map->temp_x] != 'E' &&
			   map->map[map->temp_y][map->temp_x] != 'W')
			map->temp_x++;
		if (map->map[map->temp_y][map->temp_x] != 'N' &&
			map->map[map->temp_y][map->temp_x] != 'S' &&
			map->map[map->temp_y][map->temp_x] != 'E' &&
			map->map[map->temp_y][map->temp_x] != 'W')
			map->temp_y++;
	}
	map->start_x = map->temp_x;
	map->start_y = map->temp_y;
}
