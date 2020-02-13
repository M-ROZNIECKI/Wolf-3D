/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 13:57:16 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:57:16 by mrozniec    ###    #+. /#+    ###.fr     */
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
					temp->content[i[0] + i[2]] >= 13) ||
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
	while (i < map->map_y)
	{
		if (!(map->map[i] = ft_calloc(sizeof(char *), (map->map_x + 1))))
			ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
		ft_strlcpy(map->map[i], temp->content, map->map_x);
		temp = temp->next;
	}
	ft_valid_map(map);
}

static void	ft_fill_map(t_wolf *wolf)
{
	t_lst_map		*new;
	unsigned int	temp;

	wolf->map.ch_map = (t_lst_map *)ft_lstnew(wolf->line);
	wolf->map.map_y = 1;
	wolf->map.map_x = ft_strlen(wolf->line);
	while (wolf->line[0] > '1' || wolf->line[0] < '0' ||
		(wolf->ret = get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if (wolf->line[0] == '1' || wolf->line[0] == '0')
		{
			new = (t_lst_map *)ft_lstnew(wolf->line);
			ft_lstadd_back((t_list **)&wolf->map.ch_map, (t_list *)new);
			wolf->map.map_y++;
			if ((temp = ft_strlen(wolf->line)) > wolf->map.map_x)
				wolf->map.map_x = temp;
		}
		else if (wolf->line[0] == '\0')
			temp = 0;
		else
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
		free(wolf->line);
	}
	ft_del_space(&wolf->map);
	ft_fill_tab(&wolf->map);
}

void		ft_init_map(t_wolf *wolf)
{
	while ((wolf->ret = get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if ((wolf->line[0] == '1' || wolf->line[0] == '0') && wolf->ok == 0xFF)
			ft_fill_map(wolf);
		else if (wolf->line[0] == 'N' || wolf->line[0] == 'S' ||
				wolf->line[0] == 'F' || wolf->line[0] == 'W' ||
				wolf->line[0] == 'E' || wolf->line[0] == 'C')
			ft_fillsprite();
		else if (wolf->line[0] == 'R')
			ft_fillres();
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
