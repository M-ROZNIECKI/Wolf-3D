
#ifndef WOLF_H
# define WOLF_H
# include "libftprintf.h"

typedef struct		s_wolf
{
	t_map			*t_map;
	t_sprite		*sprite;
}					t_wolf;

typedef struct		s_sprite
{
}					t_sprite;

typedef struct	s_map
{
	char			*content;
	struct s_list	*next;
}				t_map;
#endif
