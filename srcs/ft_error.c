/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:27:44 by mrozniec          #+#    #+#             */
/*   Updated: 2020/02/17 10:53:54 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 0	: an element in .cub file was set more than one times
** 1	: bad format
*/

static void	ft_one_valid_format(void)
{
	ft_printf("\n\nhere one valid format:\n\n%s%s%s%s%s%s%s%s%s%s",
			"R 1920    1080\n",
			"NO ./north_texture\nEA ./east_texture\nSO   ./south_texture\n",
			"WE ./west_texture\n\n\nF     220,100,0\n\nS ./sprite_texture\n",
			"C 225,30,0\n",
			"1 1 1 1 1 1 1 1\n",
			"1 1 0 0 S 0 0 1\n",
			"1 0 0 1 1 1 0 1\n",
			"1 0 1 0 0 1 0 1\n",
			"1 0 0 0 1 0 0 1\n",
			"1 1 1 1 1 1 1 1\n");
}

static void	ft_error_duplic_elem(int line, const char *file, const char *func)
{
	ft_printf("error at \nfile : %s\nfunction : %s\nline : %d\n"
			, file, func, line);
	ft_printf("you set an element multiple time in your .cub file%s",
			"\n\npls make a valid .cub file");
	ft_one_valid_format();
}

void		ft_error(char error, int line, const char *file, const char *func)
{
	if (error == 0)
		ft_error_duplic_elem(line, file, func);
	else if (error == -2)
		ft_printf("malloc failled in \nfile : %s\nfunction : %s\nline : %d\n"
		, file, func, line);
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
