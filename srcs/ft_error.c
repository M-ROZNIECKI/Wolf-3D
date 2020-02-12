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

void ft_error(char error, int line, const char *file, const char *function)
{
	if (error == -2)
		ft_printf("malloc failled in \nfile : %s\nfunction : %s\nline : %d\n"
		, file, function, line);
	if (error == -1)
		ft_printf("failure in processing .map file, %s",
		"check if you give us a valid file\n");
	if (error == 1)
		ft_printf("%s", "bad format for the data inside the .map file\n",
		"use one of the already made .map file or",
		" make your own well formated\n", "you need to give us all the",
		" information needed and finish by a map with the starting point",
		" surrounded by wall");
}