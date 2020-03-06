/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:47 by mrozniec          #+#    #+#             */
/*   Updated: 2020/03/06 13:25:07 by fenrir           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libftprintf.h"
# include <stdio.h>
//# include <mlx.h>

# define RES_X_MAX 2560
# define RES_Y_MAX 1440

typedef struct		s_lst_map
{
	char				*content;
	struct s_lst_map	*next;
}					t_lst_map;

typedef struct		s_sprite
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned char	f[3];
	unsigned char	c[3];
}					t_sprite;

typedef struct		s_map
{
	t_lst_map		*ch_map;
	char			**map;
	unsigned int	map_y;
	unsigned int	map_x;
	unsigned int	check_x;
	unsigned int	check_y;
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	temp_x;
	unsigned int	temp_y;
	unsigned int	pass;
}					t_map;

typedef struct		s_win
{
	int 			res_x;
	int				res_y;
}					t_win;

typedef struct		s_wolf
{
	t_win			win;
	t_map			map;
	t_sprite		sprite;
	char			*line;
	int				fd;
	int				ret;
	unsigned short	ok;
}					t_wolf;

void		ft_error(char error, int line, const char *file, const char *function);
void		ft_init_map(t_wolf *wolf);
void		ft_fill_res(t_win *win, char *entry, unsigned short *ok);
void		ft_texture(t_wolf *wolf);
void		ft_start_pos(t_map *map);
void		ft_lst_clear(t_lst_map **lst, void (*del)(void*));
void		ft_lst_add_back(t_lst_map **a_lst, t_lst_map *new);
t_lst_map	*ft_lst_new(void *content);

#endif
