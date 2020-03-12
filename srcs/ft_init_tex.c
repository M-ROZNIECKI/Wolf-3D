/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fenrir <fenrir@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:15:49 by fenrir            #+#    #+#             */
/*   Updated: 2020/03/12 15:15:10 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

void	ft_init_tex(t_wolf *wolf)
{
	if (0 == ft_strncmp(&wolf->sprite.no[ft_strlen(wolf->sprite.no) - 3], "png", 3))
		wolf->sprite.wall[0].img = mlx_png_file_to_image(wolf->win.my_mlx,\
		wolf->sprite.no, &wolf->sprite.wall[0].x, &wolf->sprite.wall[0].y);
	else if (0 == ft_strncmp(&wolf->sprite.no[ft_strlen(wolf->sprite.no) - 3], "xmp", 3))
		wolf->sprite.wall[0].img = mlx_xmp_file_to_image(wolf->win.my_mlx,\
		wolf->sprite.no, &wolf->sprite.wall[0].x, &wolf->sprite.wall[0].y);
	else
		ft_error(2, __LINE__, __FILE__, __FUNCTION__);
}