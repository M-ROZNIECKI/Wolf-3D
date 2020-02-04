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

/*
**	todo:: remove whitespaces before filling the **map
*/

static void	ft_check_map(t_map *map)
{
	t_list	*temp;
	int i[4];

	temp = map->ch_map;
	i[1] = 0;
	i[2] = 0;
	while (i[1] < map->map_y)
	{
		i[0] = 0;
		while (temp->content[i[0]])
		{
			i[3] = 0;
			while ((temp->content[i[0] + i[3]] >= 9 && temp->content[i[0] + i[3]] >= 13) || temp->content[i[0] + i[3]] == 32)
				i[3]++;
			if (n > 0)
				ft_strlcpy(&temp->content[i[0]], &temp->content[i[0] + n], map->map_x);
			i[0]++;
		}
		if (i[0] > i[2])
			i[2] = i[0];
		i[1]++;
	}
}

static void	ft_fill_tab(t_map *map)
{
	unsigned int i;
	t_list	*temp;

	i = 0;
	temp = map->ch_map
	if (!(map->map = malloc(sizeof(char *) * (map->map_y))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	while (i < map->map_y)
	{
		if (!(map->map[i] = ft_calloc(sizeof(char *), (map->map_x + 1))))
			ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
		ft_strlcpy(map->map[i], temp->content, map->map_x);
		temp = temp->next;
		if (map->map[i][0])
	}
}

static void	ft_fill_map(t_wolf *wolf)
{
	t_list	*new;
	unsigned int temp;

	wolf->map.ch_map.content = ft_lstnew(wolf->line);
	wolf->map.map_y = 1;
	wolf->map.map_x = ft_strlen(wolf->line);
	while (wolf->line[0] != '1' || (wolf->ret = get_next_line(wolf->fd, &wolf->line)) == 1)
	{
		if (wolf->line[0] == '1')
		{
			new = ft_lstnew(wolf->line);
			ft_lstadd_back(wolf->map.ch_map.content, new)
			wolf->map.map_y++;
			if ((temp = ft_strlen(wolf->line)) > wolf->map.map_x)
				wolf->map.map_x = temp;
		}
		else if (wolf->line[0] == '\0')
			temp = 0;
		else
			ft_error(1, __LINE__, __FILE__, __FUNCTION__);
	}
	ft_check_map(&wolf->map);
	ft_fill_tab(&wolf->map);
}

short	ft_init_map(t_wolf *wolf)
{
	while ((wolf->ret = getnextline(wolf->fd, &wolf->line)) == 1)
	{
		if (wolf->line[0] == '1' && wolf->ok == 0xFF)
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
	return (wolf->error);
}
