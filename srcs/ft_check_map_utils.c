/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:12:10 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/18 17:12:15 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

void	ft_select_dir(t_map *map)
{
	map->check_x = map->temp_x;
	map->check_y = map->temp_y;
	if (map->temp_x == 1)
		ft_check_u(map);
	else if (map->temp_y == 1)
		ft_check_r(map);
	else if (map->temp_x == (map->map_x - 2))
		ft_check_d(map);
	else
		ft_check_l(map);
}
