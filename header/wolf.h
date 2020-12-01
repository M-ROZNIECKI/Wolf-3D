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
# include <fcntl.h>
/*
** don't use SPRITE_SIZE > 1
*/
# define SPRITE_SIZE 1
# define RUN_SPEED 0.15
# define WALK_SPEED 0.04
# define FAST_ROT_SPEED 0.1
# define ROTATION_SPEED 0.02

typedef struct		s_lst
{
	char			*content;
	double			x;
	double			y;
	double 			dist;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_texture
{
	void			*img;
	char 			*data;
	char 			*path;
	int 			x;
	int				tex_x;
	int 			y;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_texture;

typedef struct		s_sprite
{
	t_texture		wall[6];
	char			f[3];
	char			c[3];
}					t_sprite;

typedef struct		s_map
{
	t_lst			*ch_map;
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
	double			x_ray_pos;
	double			y_ray_pos;
	double			x_ray_dir;
	double			y_ray_dir;
	double			x_side_dist;
	double			y_side_dist;
	double			x_delta_dist;
	double			y_delta_dist;
}					t_ray;

typedef struct		s_win
{
	int 			res_x_max;
	int				res_y_max;
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
	int				sprite;
	int				secret;
	double			wall_dist;
	double			ux;
}					t_frame;

typedef struct		s_spr
{
	double			x;
	double 			y;
	double			trs_x;
	double 			trs_y;
	double			inv;
	int				spr_scr_x;
	int 			spr_h;
	int 			spr_w;
	int				drw_start_y;
	int				drw_start_x;
	int				drw_end_y;
	int				drw_end_x;
}					t_spr;

typedef struct		s_wolf
{
	t_win			win;
	t_map			map;
	t_spr 			spr_data;
	t_sprite		sprite;
	t_player		player;
	t_ray			ray;
	t_texture 		image;
	t_frame			frame;
	t_lst 			*spr;
	char			*line;
	int				fd;
	int				d;
	int				tex_y;
	int				ret;
	int				mov_dwn;
	unsigned short	ok;
	unsigned short	sel;
}					t_wolf;

void	ft_error(char error, int line, const char *file, const char *function);
void	ft_init_map(t_wolf *wolf);
void	ft_fill_res(t_win *win, char *entry, unsigned short *ok, t_wolf *wolf);
void	ft_texture(t_wolf *wolf);
int		ft_test_pos(t_map *map);
void	ft_lst_clear(t_lst **lst, void (*del)(void*));
void	ft_lst_add_back(t_lst **a_lst, t_lst *new);
void	ft_lst_add_frt(t_lst **alst, t_lst *new);
t_lst	*ft_lst_new(void *content);
int		ft_check_list(t_wolf *wolf);
void	ft_init(t_wolf *wolf);
void	ft_init_tex(t_wolf *wolf);
void	ft_frame(t_wolf *wolf);
void	ft_draw(int x, int draw_start, int draw_end, t_wolf *wolf);
void	ft_draw2(int x, int draw_start, t_wolf *wolf);
void	ft_draw3(int x, int draw_start, t_wolf *wolf);
void	ft_wall_detec_init(t_wolf *wolf);
void	ft_wall_detec(t_wolf *wolf);
int 	ft_add_sprite2(t_wolf *wolf);
void	choose_texture(t_wolf *wolf);
void	texture_calc(t_wolf *wolf);
int		ft_press(int keycode, t_wolf *wolf);
int		ft_release(int key, t_wolf *wolf);
int		ft_move(t_wolf *wolf);
int 	ft_leave(t_wolf *wolf);
void	ft_bmp(t_wolf *wolf);
void	ft_sprite(t_wolf *wolf, double *wall_dist_buf);
void 	ft_free(void *x);
int 	ft_free_sel(t_wolf *wolf, int code);
int 	ft_free_tex(t_wolf *wolf, int n);

#endif
