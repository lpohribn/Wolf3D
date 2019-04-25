/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:49:16 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/14 14:49:19 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define H 1000
# define W 1000
# define BUFF_S 65536

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <errno.h>

typedef	struct	s_floor
{
	double		floor_wall_x;
	double		floor_wall_y;
	double		dist_wall;
	double		dist_player;
	double		cur_dist;
	int			fl_tex_x;
	int			fl_tex_y;
}				t_floor;

typedef	struct	s_texture
{
	int			tex_w;
	int			tex_h;
	int			tex_x;
	int			tex_y;
	void		*img;
	int			bp;
	int			bl;
	int			*str;
	int			num;
	int			e;
}				t_texture;

typedef	struct	s_map
{
	int			map_x;
	int			map_y;
	int			width;
	int			height;
}				t_map;

typedef	struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		cam_x;
	double		raydir_x;
	double		raydir_y;
	double		mvspeed;
	double		rotspeed;
	double		sdist_x;
	double		sdist_y;
	double		ddist_x;
	double		ddist_y;
	double		pwall_dist;
	double		wall_x;
	int			side;
	int			line_h;
	int			y0;
	int			y1;
	int			hit;
}				t_player;

typedef	struct	s_flag
{
	int			left;
	int			right;
	int			down;
	int			up;
	int			tex_num;
}				t_flag;

typedef	struct	s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			**map;
	int			*str;
	int			bp;
	int			bl;
	int			color;
	int			endian;
	t_player	p;
	t_map		m;
	t_texture	t[12];
	t_flag		fl;
	t_texture	f[2];
	t_texture	w[4];
	t_floor		fc;
}				t_info;

int				ft_open(char *argv);
char			*ft_read_map(int fd);
int				ft_validation(char **array, t_info *w);
void			ft_current_position(t_info *w);
int				ft_check_confines(t_info *w);
int				ft_create_mass(t_info *w, char **array);
int				ft_raycasting(t_info *w);
void			ft_draw(t_info *w);
void			ft_draw_texture(t_info *w, int x);
void			ft_put_pixel(t_info *w, int x, int y, int color);
void			ft_textures(t_info *w);
void			ft_minimap(t_info *w);
void			ft_weapon(t_info *w);
void			ft_floor_ceiling(t_info *w, int x);
void			ft_move(t_info *w);
void			ft_events(t_info w);
int				ft_key_unpressed(int key, t_info *w);
int				ft_key(int key, t_info *w);
void			ft_error(int n);
int				ft_exit(void);

#endif
