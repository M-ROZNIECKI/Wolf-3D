
#ifndef WOLF_H
# define WOLF_H
# include "libftprintf.h"

typedef struct		s_wolf
{
	t_map			**map;
	t_sprite		*sprite;
	char 			*file;
	char 			*line;
	int				fd;
	char 			ret;
	char 			ok;
	short			error;
}					t_wolf;

typedef struct		s_sprite
{
	char 			*no;
	char 			*so;
	char 			*we;
	char 			*ea;
	char 			*s;
	char 			*f;
	char 			*c;
}					t_sprite;

typedef struct	s_map_init
{
	char			*content;
	struct s_list	*next;
}				t_map_init;

typedef struct	s_map
{
	char 		**map;
}				t_map;

#endif
