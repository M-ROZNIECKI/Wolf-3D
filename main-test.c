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

int main(void)
{
	void *fistyland;
	void *my_mlx;


	system("clear");
	ft_error(1, __LINE__, __FILE__, __FUNCTION__);
	my_mlx = mlx_init();
	fistyland = mlx_new_window(my_mlx, 1920, 1080, "Hello");
	mlx_loop(my_mlx);
	return (0);
}
