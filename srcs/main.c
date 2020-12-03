/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:02:37 by mrozniec          #+#    #+#             */
/*   Updated: 2020/12/03 22:38:07 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 0	: an element in .cub file was set more than one times
** 1	: bad format
** 2	: you need to give in param the path to the .cub file
** 		  containing the data needed to make the map
*/

int	main(int argc, char const *argv[])
{
	t_wolf		*wolf;

	if (argc < 2 || (argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	if (!(wolf = malloc(sizeof(t_wolf))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	wolf->win.name = ft_strdup(argv[1]);
	if (0 != (ft_strncmp(&wolf->win.name[ft_strlen(wolf->win.name) - 4],\
	".cub", 4)))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	wolf->fd = open(wolf->win.name, O_RDONLY);
	wolf->ok = 0;
	ft_init(wolf);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		ft_bmp(wolf);
	mlx_hook(wolf->win.win, 2, (1L << 0), ft_press, wolf);
	mlx_hook(wolf->win.win, 3, (1L << 1), ft_release, wolf);
	mlx_hook(wolf->win.win, 17, 1, ft_leave, wolf);
	mlx_hook(wolf->win.win, 33, (1L << 17), ft_leave, wolf);
	mlx_loop_hook(wolf->win.my_mlx, ft_move, wolf);
	mlx_loop(wolf->win.my_mlx);
	return (0);
}
