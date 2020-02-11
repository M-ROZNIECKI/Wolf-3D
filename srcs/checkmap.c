/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkmap.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/04 14:49:32 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/04 14:49:32 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

static void	ft_check_u(t_map *map);
static void	ft_check_d(t_map *map);
static void	ft_check_l(t_map *map);
static void	ft_check_r(t_map *map);
extern void ft_error(char error, int line, char *file, const char function[11]);

static void	ft_start_pos(t_map *map)
{
	map->temp_y = 0;
	map->temp_x = 0;
	while (map->map[map->temp_y] &&
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

static void	ft_check_u(t_map *map)
{
	while (map->map[map->temp_y - 1][map->temp_x] != '1')
	{
		map->temp_y--;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return;
		if (map->temp_y == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y][map->temp_x - 1] != '1')
		{
			ft_check_l(map);
			return;
		}
	}
	ft_check_r(map);
	return;
}

static void	ft_check_d(t_map *map)
{
	while (map->map[map->temp_y + 1][map->temp_x] != '1')
	{
		map->temp_y++;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return;
		if (map->temp_y == map->map_y || map->map[map->temp_y][map->temp_x] == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y][map->temp_x + 1] != '1')
		{
			ft_check_r(map);
			return;
		}
	}
	ft_check_l(map);
	return;
}

static void	ft_check_r(t_map *map)
{
	while (map->map[map->temp_y][map->temp_x + 1] != '1')
	{
		map->temp_x++;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return;
		if (map->temp_x == map->map_x || map->map[map->temp_y][map->temp_x] == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y - 1][map->temp_x] != '1')
		{
			ft_check_u(map);
			return;
		}
	}
	ft_check_d(map);
	return;
}

static void	ft_check_l(t_map *map)
{
	while (map->map[map->temp_y][map->temp_x - 1] != '1')
	{
		map->temp_x--;
		if ((map->check_x == map->temp_x) && (map->check_y == map->temp_y))
			return;
		if (map->check_x > map->temp_x)
		{
			map->check_x = map->temp_x;
			map->check_y = map->temp_y;
		}
		if (map->temp_x == map->map_x || map->map[map->temp_y][map->temp_x] == 0)
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		if (map->map[map->temp_y + 1][map->temp_x] != '1')
		{
			ft_check_d(map);
			return;
		}
	}
	ft_check_u(map);
	return;
}

static void	ft_valid_map(t_map *map)
{
	ft_start_pos(map);
	map->temp_x = map->start_x;
	map->temp_y = map->start_y;
	if (map->temp_x <= 0)
		ft_error(1, __LINE__, __FILE__, __FUNCTION__);
	while (map->map[map->temp_y][map->temp_x - 1] != '1')
		map->temp_x--;
	map->check_x = map->temp_x;
	map->check_y = map->temp_y;
	ft_check_u(map);
}

static void	ft_del_space(t_map *map)
{
	t_list	*temp;
	int i[3];

	temp = &map->ch_map;
	i[1] = 0;
	while (temp)
	{
		i[0] = 0;
		while (temp->content[i[0]])
		{
			i[2] = 0;
			while ((temp->content[i[0] + i[2]] >= 9 && temp->content[i[0] + i[2]] >= 13) || temp->content[i[0] + i[2]] == 32)
				i[2]++;
			if (n > 0)
				ft_strlcpy(temp->content[i[0]], temp->content[i[0] + i[2]], map->map_x);
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
	unsigned int i;
	t_list	*temp;

	i = 0;
	temp = map->ch_map
	if (!(map->map = ft_calloc(sizeof(char *), (map->map_y + 1))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	while (i < map->map_y)
	{
		if (!(map->map[i] = ft_calloc(sizeof(char *), (map->map_x + 1))))
			ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
		ft_strlcpy(map->map[i], temp->content, map->map_x);
		temp = temp->next;
		if (map->map[i][0])
	}
	ft_valid_map();
}

static void	ft_fill_map(t_wolf *wolf)
{
	t_list	*new;
	unsigned int temp;

	wolf->map.ch_map.content = ft_lstnew(wolf->line);
	wolf->map.map_y = 1;
	wolf->map.map_x = ft_strlen(wolf->line);
	while (wolf->line[0] > '1' || wolf->line[0] < '0' || (wolf->ret = get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if (wolf->line[0] == '1' || wolf->line == '0')
		{
			new = ft_lstnew(wolf->line);
			ft_lstadd_back(wolf->map.ch_map.content, new);
			wolf->map.map_y++;
			if ((temp = ft_strlen(wolf->line)) > wolf->map.map_x)
				wolf->map.map_x = temp;
		}
		else if (wolf->line[0] == '\0')
			temp = 0;
		else
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
	}
	ft_del_space(&wolf->map);
	ft_fill_tab(&wolf->map);
}

void	ft_init_map(t_wolf *wolf)
{
	while ((wolf->ret = getnextline(wolf->fd, &wolf->line)) == 1)
	{
		if ((wolf->line[0] == '1' || wolf->line[0] == '0') && wolf->ok == 0xFF)
			ft_fillmap(wolf);
		else if (wolf->line[0] == 'N' || wolf->line[0] == 'S' || wolf->line[0] == 'F' || wolf->line[0] == 'W' || wolf->line[0] == 'E' || wolf->line[0] == 'C')
			ft_fillsprite();
		else if (wolf->line[0] == 'R')
			ft_fillres();
		else if (wolf->line[0] != '\0')
		{
			free(wolf->line);
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		}
		free(wolf->line);
	}
	if (wolf->ret == -1)
		ft_error(-1, __LINE__, __FILE__, __FUNCTION__);
}
