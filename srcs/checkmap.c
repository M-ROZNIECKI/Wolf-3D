/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:26:55 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/17 10:27:02 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

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
		//printf("\n\n\n%d\n\n\n", map->temp_y);
		printf("\n%-2d :", map->temp_y);
		map->temp_x = 0;
		while (map->map[map->temp_y][map->temp_x] &&
				map->map[map->temp_y][map->temp_x] != 'N' &&
				map->map[map->temp_y][map->temp_x] != 'S' &&
				map->map[map->temp_y][map->temp_x] != 'E' &&
				map->map[map->temp_y][map->temp_x] != 'W')
		{
			printf("%c", map->map[map->temp_y][map->temp_x]);
			map->temp_x++;
		}
		if (map->map[map->temp_y][map->temp_x] != 'N' &&
			map->map[map->temp_y][map->temp_x] != 'S' &&
			map->map[map->temp_y][map->temp_x] != 'E' &&
			map->map[map->temp_y][map->temp_x] != 'W')
			map->temp_y++;
	}
	map->start_x = map->temp_x;
	map->start_y = map->temp_y;
	printf("\n\n\n");
}

void	ft_check_u(t_map *map)
{
	while (map->map[map->temp_y - 1][map->temp_x] != '1')
	{
		map->temp_y--;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return ;
		if (map->temp_y == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y][map->temp_x - 1] != '1')
		{
			ft_check_l(map);
			return ;
		}
	}
	ft_check_r(map);
	return ;
}

void	ft_check_d(t_map *map)
{
	while (map->map[map->temp_y + 1][map->temp_x] != '1')
	{
		map->temp_y++;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return ;
		if (map->temp_y == map->map_y ||
		map->map[map->temp_y][map->temp_x] == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y][map->temp_x + 1] != '1')
		{
			ft_check_r(map);
			return ;
		}
	}
	ft_check_l(map);
	return ;
}

void	ft_check_r(t_map *map)
{
	while (map->map[map->temp_y][map->temp_x + 1] != '1')
	{
		map->temp_x++;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return ;
		if (map->temp_x == map->map_x ||
		map->map[map->temp_y][map->temp_x] == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y - 1][map->temp_x] != '1')
		{
			ft_check_u(map);
			return ;
		}
	}
	ft_check_d(map);
	return ;
}

void	ft_check_l(t_map *map)
{
	while (map->map[map->temp_y][map->temp_x - 1] != '1')
	{
		map->temp_x--;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return ;
		if (map->check_x > map->temp_x)
		{
			map->check_x = map->temp_x;
			map->check_y = map->temp_y;
		}
		if (map->temp_x == map->map_x ||
		map->map[map->temp_y][map->temp_x] == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y + 1][map->temp_x] != '1')
		{
			ft_check_d(map);
			return ;
		}
	}
	ft_check_u(map);
	return ;
}