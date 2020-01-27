/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main-test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 10:21:12 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 19:27:30 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>

int main(void)
{
	void *fistyland;
	void *my_mlx;

	my_mlx = mlx_init();
	fistyland = mlx_new_window(my_mlx, 1600, 900, "Title");
	mlx_loop(my_mlx);
	return (0);
}
