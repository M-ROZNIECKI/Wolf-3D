//
// Created by fenrir on 03/09/2020 14:22:16.
//

#include "../header/wolf.h"

static void	ft_fill_data(int fd, t_wolf *wolf)
{
	char	*data;
	int		x;
	int		y;
	int		sizeline;

	sizeline = (3 * wolf->win.res_x);
	if ((sizeline % 4) != 0)
		sizeline += 4 - (sizeline % 4);
	y = wolf->win.res_y;
	if (!(data = malloc(sizeof(char) * sizeline)))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	while (--y >= 0)
	{
		x = 0;
		ft_memset(data, 0, sizeline);
		while (x < (wolf->win.res_x) * 3)
		{
			data[x] = wolf->image.data[(x / 3) * 4 + 4 * wolf->win.res_x * y];
			data[x + 1] = wolf->image.data[(x / 3) * 4 + 4 * wolf->win.res_x * y + 1];
			data[x + 2] = wolf->image.data[(x / 3) * 4 + 4 * wolf->win.res_x * y + 2];
			x += 3;
		}
		if (write(fd, data, sizeline) == -1)
			ft_error(10, __LINE__, __FILE__, __FUNCTION__);
	}
	free(data);
}

static void	ft_fill_header(int fd, t_wolf *wolf)
{
	char	*header;

	if (!(header = ft_calloc(sizeof(char), 55)))
		ft_error(-2, __LINE__, __FILE__, __FUNCTION__);
	header[0] = 0x42;
	header[1] = 0x4D;
	header[0x0A] = 0x36;
	header[0x0E] = 0x28;
	header[0x012] = wolf->win.res_x & 0x000000FF;
	header[0x013] = (wolf->win.res_x >> 8) & 0x000000FF;
	header[0x014] = (wolf->win.res_x >> 16) & 0x000000FF;
	header[0x015] = (wolf->win.res_x >> 24) & 0x000000FF;
	header[0x016] = wolf->win.res_y & 0x000000FF;
	header[0x017] = (wolf->win.res_y >> 8) & 0x000000FF;
	header[0x018] = (wolf->win.res_y >> 16) & 0x000000FF;
	header[0x019] = (wolf->win.res_y >> 24) & 0x000000FF;
	header[0x01A] = 0x01;
	header[0x01C] = 0x18;
	if (write(fd, header, 54) == -1)
		ft_error(10, __LINE__, __FILE__, __FUNCTION__);
	free(header);
}

void		ft_bmp(t_wolf *wolf)
{
	int fd;

	fd = open("save.bmp", O_CREAT | O_WRONLY, 0777);
	ft_fill_header(fd, wolf);
	ft_fill_data(fd, wolf);
	close(fd);
}