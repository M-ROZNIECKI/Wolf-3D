/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:47 by mrozniec          #+#    #+#             */
/*   Updated: 2020/03/12 15:15:10 by mrozniec         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "libftprintf.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>

# define RES_X_MAX 2560
# define RES_Y_MAX 1440

typedef struct		s_lst_map
{
	char				*content;
	struct s_lst_map	*next;
}					t_lst_map;

typedef struct		s_texture
{
	void			*img;
	char 			*data;
	char 			*path;
	int 			x;
	int 			y;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_texture;

typedef struct		s_sprite
{
	t_texture		wall[5];
	char			f[3];
	char			c[3];
}					t_sprite;

typedef struct		s_map
{
	t_lst_map		*ch_map;
	char			**map;
	char 			dir;
	unsigned int	map_y;
	unsigned int	map_x;
	unsigned int	check_x;
	unsigned int	check_y;
	unsigned int	start_x;
	unsigned int	start_y;
	unsigned int	temp_x;
	unsigned int	temp_y;
	unsigned int	hit;
}					t_map;

typedef struct		s_player
{
	double			x_camera;
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_old_dir;
	double			x_old_plane;
	double			move_speed;
	double			turn_rate;
	int				turn_right;
	int				turn_left;
	int				forward;
	int				backward;
}					t_player;

typedef struct		s_ray
{
	double			x_ray_position;
	double			y_ray_position;
	double			x_ray_direction;
	double			y_ray_direction;
	double			x_side_distance;
	double			y_side_distance;
	double			x_delta_distance;
	double			y_delta_distance;
}					t_ray;

typedef struct		s_win
{
	int 			res_x;
	int				res_y;
	void			*my_mlx;
	void			*win;
	char 			*name;
}					t_win;

typedef struct		s_frame
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				side;
	int				x;
	int 			item;
	double			wall_distance;
	double			ux;
}					t_frame;

typedef struct		s_wolf
{
	t_win			win;
	t_map			map;
	t_sprite		sprite;
	t_player		player;
	t_ray			ray;
	t_texture 		image;
	t_frame			frame;
	char			*line;
	int				fd;
	int				ret;
	unsigned short	ok;
	unsigned short	selec;
}					t_wolf;

void		ft_error(char error, int line, const char *file, const char *function);
void		ft_init_map(t_wolf *wolf);
void		ft_fill_res(t_win *win, char *entry, unsigned short *ok);
void		ft_texture(t_wolf *wolf);
void		ft_test_pos(t_map *map);
void		ft_lst_clear(t_lst_map **lst, void (*del)(void*));
void		ft_lst_add_back(t_lst_map **a_lst, t_lst_map *new);
t_lst_map	*ft_lst_new(void *content);
void		ft_init(t_wolf *wolf);
void		ft_init_tex(t_wolf *wolf);
void		ft_frame(t_wolf *wolf);
void		ft_draw(int x, int draw_start, int draw_end, t_wolf *wolf);
void		ft_wall_detec_init(t_wolf *wolf);
void		ft_wall_detec(t_wolf *wolf);
void		choose_texture(t_wolf *wolf);
void		texture_calc(t_wolf *wolf);
int			ft_press(int keycode, t_wolf *wolf);
int			ft_release(int key, t_wolf *wolf);
int			ft_move(t_wolf *wolf);
int 		ft_leave(t_wolf *wolf);
void		ft_bmp(t_wolf *wolf);

#endif
