/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:33:51 by mrozniec          #+#    #+#             */
/*   Updated: 2020/05/05 10:43:11 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_test_pos(t_map *map)
{
	static unsigned int i = 0;
	if (map->map[map->temp_y][map->temp_x] != '0')
	{
		map->start_x = map->temp_x;
		map->start_y = map->temp_y;
		i++;
	}
	if (map->temp_y == 0 || map->temp_x == 0 ||
		map->temp_y == map->map_y - 1 || i > 1 ||
		map->map[map->temp_y - 1][map->temp_x - 1] == ' ' ||
		map->map[map->temp_y - 1][map->temp_x] == ' ' ||
		map->map[map->temp_y - 1][map->temp_x + 1] == ' ' ||
		map->map[map->temp_y + 1][map->temp_x - 1] == ' ' ||
		map->map[map->temp_y + 1][map->temp_x] == ' ' ||
		map->map[map->temp_y + 1][map->temp_x + 1] == ' ' ||
		map->map[map->temp_y][map->temp_x - 1] == ' ' ||
		map->map[map->temp_y][map->temp_x + 1] == ' ' ||
		map->map[map->temp_y][map->temp_x + 1] == '\0')
		ft_error(1, __LINE__, __FILE__, __FUNCTION__);
}
