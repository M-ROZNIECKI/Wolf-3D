//
// Created by fenrir on 03/09/2020 14:22:16.
//

#include "../header/wolf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char	*ft_lit_end_4(int num)
{
	unsigned int temp;
	char *hex;

	temp = ft_itoa_base(num & 0x000000FF, "0123456789ABCDEF");
	if (ft_strlen(temp) == 1)
		temp = ft_strjoinmod("0", temp, 2);
	hex =  ft_strjoinmod(temp, " ", 1);
	temp = ft_itoa_base((num >> 8) & 0x000000FF, "0123456789ABCDEF");
	if (ft_strlen(temp) == 1)
		temp = ft_strjoinmod("0", temp, 2);
	hex = ft_strjoinmod(hex, temp, 3);
	hex = ft_strjoinmod(hex, " ", 1);
	temp = ft_itoa_base((num >> 16) & 0x000000FF, "0123456789ABCDEF");
	if (ft_strlen(temp) == 1)
		temp = ft_strjoinmod("0", temp, 2);
	hex = ft_strjoinmod(hex, temp, 3);
	hex = ft_strjoinmod(hex, " ", 1);
	temp = ft_itoa_base((num >> 24) & 0x000000FF, "0123456789ABCDEF");
	if (ft_strlen(temp) == 1)
		temp = ft_strjoinmod("0", temp, 2);
	hex = ft_strjoinmod(hex, temp, 3);
	hex = ft_strjoinmod(hex, "\n", 1);
	return (hex);
}

static void	ft_fill_data(int fd, t_wolf *wolf)
{
	int x;
	int y;
	char *data;

	y = wolf->image.y;
	x = wolf->image.x;
	data = ft_strdup("");
	while(--y >= 0)
		while (--x >= 0)
			data = ft_strjoinmod(data, ft_lit_end_4(\
				(wolf->image.data[x * 4 + 4 * wolf->win.res_x * y] << 16) +\
				(wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 1] << 8) +\
				(wolf->image.data[x * 4 + 4 * wolf->win.res_x * y + 2])), 3);
}


static void	ft_fill_header(int fd, t_wolf *wolf)
{
	char *header;

	header = ft_strdup("42 4D\n00 00 00 00\n00 00 00 00\n36 00 00 00\n");
	header = ft_strjoinmod(header, "\n28 00 00 00\n", 1);
	header = ft_strjoinmod(header, ft_lit_end_4(wolf->image.x), 3);
	header = ft_strjoinmod(header, ft_lit_end_4(wolf->image.y), 3);
	header = ft_strjoinmod(header, "01 00\n18 00\n00 00 00 00\n", 1);
	header = ft_strjoinmod(header, "00 00 00 00\n00 00 00 00\n", 1);
	header = ft_strjoinmod(header, "00 00 00 00\n00 00 00 00\n", 1);
	header = ft_strjoinmod(header, "00 00 00 00\n\n", 1);
	write(fd, header, ft_strlen(header));
}

void		ft_bmp(t_wolf *wolf)
{
	int fd;

	fd = open("save.bmp", O_CREAT);
	ft_fill_header(fd, wolf);
	ft_fill_data(fd, wolf);
}