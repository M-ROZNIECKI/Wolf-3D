/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:44:34 by mrozniec          #+#    #+#             */
/*   Updated: 2020/05/02 10:35:08 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 0	: an element in .cub file was set more than one times
** 1	: bad format
** TODO 2	: sprite not in xmp or png
*/

static void	ft_one_valid_format(void)
{
	ft_printf("\n\nhere one valid format:\n\n%s%s%s%s%s%s%s%s%s%s",
			"R 1920    1080\n",
			"NO ./north_texture\nEA ./east_texture\nSO   ./south_texture\n",
			"WE ./west_texture\n\n\nF     220,100,0\n\nS ./sprite_texture\n",
			"C 225,30,0\n",
			"11111111 111\n",
			"1100S0011101\n",
			"100111000001\n",
			"101001010001\n",
			"100010011101\n",
			"11111111 111\n");
}

static void	ft_error_duplic_elem(void)
{
	ft_printf("you set an element multiple time in your .cub file%s",
			"\n\npls make a valid .cub file\n");
	ft_one_valid_format();
}

void		ft_error(char error, int line, const char *file, const char *func)
{
	ft_printf("error in\nfile : %s\nfunction : %s\nline : %d\n",
			file, func, line);
	if (error == 0)
		ft_error_duplic_elem();
	else if (error == -2)
		ft_printf("malloc failed");
	else if (error == -1)
		ft_printf("failure in processing .cub file, %s",
		"check if you give us a valid file\n");
	else if (error == 1)
	{
		ft_printf("%s%s%s%s", "bad format inside the .cub file\n",
				"use one of the already made .cub file or",
				" make your own well formatted\nyou need to give us all the",
				" information needed and finish by a closed map");
		ft_one_valid_format();
	}
	exit(0);
}
