
#ifndef WOLF_H
# define WOLF_H
# include "libftprintf.h"

typedef struct		s_sprite
{
	void 			*no;
	void 			*so;
	void 			*we;
	void 			*ea;
	void 			*s;
	void 			*f;
	void 			*c;
}					t_sprite;

typedef struct		s_map
{
	t_list
	ch_map;
	char 			**map;
	unsigned int	map_y;
	unsigned int	map_x;
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	check_x;
	unsigned int	check_y;
	unsigned int	temp_x;
	unsigned int	temp_y;
}					t_map;

typedef struct		s_wolf
{
	t_map			map;
	t_sprite		sprite;
	char 			*file;
	char 			*line;
	int				fd;
	char			ret;
	unsigned char	ok;
	short			error;
}					t_wolf;

#endif
