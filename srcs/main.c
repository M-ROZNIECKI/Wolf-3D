/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:00 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/27 19:10:02 by mrozniec         ###   ########lyon.fr   */
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

	if (!(wolf = malloc(sizeof(t_wolf))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	wolf->win.name = ft_strdup(argv[1]);
	wolf->fd = open(wolf->win.name, O_RDONLY);
	wolf->ok = 0;
	ft_init(wolf);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		ft_bmp(wolf);
	mlx_hook(wolf->win.win, 2, (1L << 0), ft_press, wolf);
	mlx_hook(wolf->win.win, 3, (1L << 1), ft_release, wolf);
	mlx_hook(wolf->win.win, 17, 0, ft_leave, (void *)0);
	mlx_loop_hook(wolf->win.my_mlx, ft_move, wolf);
	mlx_loop(wolf->win.my_mlx);
	return (0);
}
