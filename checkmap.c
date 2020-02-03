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

int	ft_checkmap(t_wolf *wolf)
{
	while ((wolf->ret = getnextline(wolf->fd, &wolf->line)) != 0)
	{
		if (wolf->line[0] == '1' && wolf->ok == 0xFF)
			ft_fillmap();
		else if (wolf->line[0] == 'N' && wolf->line[1] == 'O')//	0b00000010
			ft_fillsprite();
		else if (wolf->line[0] == 'S' && wolf->line[1] == 'O')//	0b00000100
			ft_fillsprite();
		else if (wolf->line[0] == 'W' && wolf->line[1] == 'E')//	0b00001000
			ft_fillsprite();
		else if (wolf->line[0] == 'E' && wolf->line[1] == 'A')//	0b00010000
			ft_fillsprite();
		else if (wolf->line[0] == 'S' && wolf->line[1] != 'O')//	0b00100000
			ft_fillsprite();
		else if (wolf->line[0] == 'F')//						0b01000000
			ft_fillsprite();
		else if (wolf->line[0] == 'C')//						0b10000000
			ft_fillsprite();
		else if (wolf->line[0] == 'R')//						0b00000001
			ft_fillres();
		else if (wolf->line[0] != '\0' || wolf->ret == -1)
			ft_error(wolf->ret, line);//							-1 error durring processing of the map file \\ 1 map file incorectly formated
		free(line);
	}
	return (wolf->error);
}
