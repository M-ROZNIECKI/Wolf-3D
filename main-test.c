/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:56:21 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/17 13:56:28 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "header/wolf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
//	void *fistyland;
//	void *my_mlx;
	t_wolf *wolf;

	if (!(wolf = malloc(sizeof(t_wolf))))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	if (argc == 2)
	{
		wolf->fd = open(argv[1], O_RDONLY);
		wolf->ok = 0;
		ft_init_map(wolf);
	}/*
	my_mlx = mlx_init();
	fistyland = mlx_new_window(my_mlx, 1920, 1080, "Hello");
	mlx_loop(my_mlx);*/
	return (0);
}
