/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:21:57 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 17:21:57 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

int	ft_test_pos(t_map *map)
{
	static unsigned int i = 0;

	if ((map->map[map->temp_y][map->temp_x] < '0') ||
	(map->map[map->temp_y][map->temp_x] > '3'))
	{
		map->start_x = map->temp_x;
		map->start_y = map->temp_y;
		map->dir = map->map[map->temp_y][map->temp_x];
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
		return (1);
	return (0);
}

int	ft_add_sprite2(t_wolf *wolf)
{
	if (!(wolf->spr = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	wolf->spr->x = wolf->map.map_x + 0.5;
	wolf->spr->y = wolf->map.map_y + 0.5;
	wolf->spr->dist = pow(wolf->player.x_pos - wolf->spr->x, 2) +\
			pow(wolf->player.y_pos - wolf->spr->y, 2);
	wolf->spr->next = NULL;
	wolf->frame.sprite = 2;
	return (1);
}
