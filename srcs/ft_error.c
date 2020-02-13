/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 14:00:28 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 14:00:28 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/wolf.h"

/*
** code error:
** -2	: malloc fail
** -1	: error processing .map file
** 1	: bad format
*/

static void	ft_one_valid_format(void)
{
	printf("\n\nhere one valid format:\n\n%s%s%s%s%s%s%s%s%s%s",
			"R 1920    1080\n",
			"NO ./north_texture\nEA ./east_texture\nSO   ./south_texture\n",
			"F     220,100,0\n\nWE ./west_texture\n\n\nS ./sprite_texture\n",
			"C 225,30,0\n",
			"11111111\n",
			"11000001\n",
			"10011101\n",
			"10110101\n",
			"10000101\n",
			"11111111\n");
}

void		ft_error(char error, int line, const char *file, const char *func)
{
	if (error == -2)
		ft_printf("malloc failled in \nfile : %s\nfunction : %s\nline : %d\n"
		, file, func, line);
	if (error == -1)
		ft_printf("failure in processing .map file, %s",
		"check if you give us a valid file\n");
	if (error == 1)
	{
		ft_printf("%s%s%s%s", "bad format inside the .map file\n",
				"use one of the already made .map file or",
				" make your own well formatted\nyou need to give us all the",
				" information needed and finish by a closed map");
		ft_one_valid_format();
	}
	exit(0);
}
