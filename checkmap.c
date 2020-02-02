/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   checkmap.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/29 11:32:56 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 19:05:20 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header/wolf.h"

int	checkmap(char *filemap)
{
	char *line;
	int fd;
	int ret;
	char ok;

	fd = open(filemap);
	while ((ret = getnextline(fd, &line)) != 0)
	{
		if (line[0] == '1' && ok == 0xFF)
			ft_fillmap();
		else if (line[0] == 'N' && line[1] == 'O')//	0b00000010
			ft_fillsprite();
		else if (line[0] == 'S' && line[1] == 'O')//	0b00000100
			ft_fillsprite();
		else if (line[0] == 'W' && line[1] == 'E')//	0b00001000
			ft_fillsprite();
		else if (line[0] == 'E' && line[1] == 'A')//	0b00010000
			ft_fillsprite();
		else if (line[0] == 'S' && line[1] != 'O')//	0b00100000
			ft_fillsprite();
		else if (line[0] == 'F')//						0b01000000
			ft_fillsprite();
		else if (line[0] == 'C')//						0b10000000
			ft_fillsprite();
		else if (line[0] == 'R')//						0b00000001
			ft_fillres();
		else if (line[0] != '\0' || ret == -1)
		{
			free(line);
			ft_error(ret);//							-1 error durring processing of the map file \\ 1 map file incorectly formated
		}
	}
}
