/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:00 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/27 19:10:02 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "minilibx/mlx.h"
#include "header/wolf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 0	: an element in .cub file was set more than one times
** 1	: bad format
** 2	: you need to give in param the path to the .cub file containing the data needed to make the map
*/

int main(int argc, char const *argv[])
{
//	void *fistyland;
//	void *my_mlx;
	t_wolf *wolf;

	if (!(wolf = malloc(sizeof(t_wolf))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	if (argc == 2) {
		wolf->win.name = ft_strdup(argv[1]);
		wolf->fd = open(wolf->win.name, O_RDONLY);
		wolf->ok = 0;
		ft_init_map(wolf);
		printf("everything is ok");
//		my_mlx = mlx_init();
//		fistyland = mlx_new_window(my_mlx, wolf->win.res_x, wolf->win.res_y, "E1M1");
//		mlx_loop(my_mlx);
	}
	return (0);
}
