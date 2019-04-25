/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:18:37 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/20 17:18:40 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static t_texture	ft_load(t_info *w, char *name)
{
	t_texture	tmp;

	if (!(tmp.img = mlx_xpm_file_to_image(w->mlx, name, &tmp.tex_w,
		&tmp.tex_h)))
		ft_error(-7);
	if (!(tmp.str = (int*)mlx_get_data_addr(tmp.img, &tmp.bp, &tmp.bl, &tmp.e)))
		ft_error(-7);
	return (tmp);
}

void				ft_textures(t_info *w)
{
	w->t[0] = ft_load(w, "./texture/skirp.xpm");
	w->t[1] = ft_load(w, "./texture/StoneUWD.xpm");
	w->t[2] = ft_load(w, "./texture/tumb.xpm");
	w->t[3] = ft_load(w, "./texture/bookshelf.xpm");
	w->t[4] = ft_load(w, "./texture/kirpich.xpm");
	w->t[5] = ft_load(w, "./texture/Brownbrickl.xpm");
	w->t[6] = ft_load(w, "./texture/wood.xpm");
	w->t[7] = ft_load(w, "./texture/orel.xpm");
	w->t[8] = ft_load(w, "./texture/Tilesbrn.xpm");
	w->t[9] = ft_load(w, "./texture/greystone.xpm");
	w->w[0] = ft_load(w, "./weapons/knife.xpm");
	w->w[1] = ft_load(w, "./weapons/gun.xpm");
	w->w[2] = ft_load(w, "./weapons/fire.xpm");
	w->w[3] = ft_load(w, "./weapons/bazooka.xpm");
	w->f[0] = ft_load(w, "./texture/potolok.xpm");
	w->f[1] = ft_load(w, "./texture/polser.xpm");
}

static void			ft_sides_of_wall(t_info *w, int x, int n)
{
	int y;
	int d;

	y = w->p.y0;
	while (y < w->p.y1)
	{
		d = y * 256 - H * 128 + w->p.line_h * 128;
		w->t[n].tex_y = ((d * w->t[n].tex_h) / w->p.line_h) / 256;
		w->color = w->t[n].str[(int)(w->t[n].tex_h *
			w->t[n].tex_y + w->t[n].tex_x)];
		if (w->p.side == 0)
			w->color = (w->color >> 1) & 8355711;
		ft_put_pixel(w, x, y, w->color);
		y++;
	}
}

void				ft_draw_texture(t_info *w, int x)
{
	int	n;

	n = w->map[w->m.map_x][w->m.map_y] - 1;
	if (w->p.side == 0)
		w->p.wall_x = w->p.pos_y + w->p.pwall_dist * w->p.raydir_y;
	else
		w->p.wall_x = w->p.pos_x + w->p.pwall_dist * w->p.raydir_x;
	w->p.wall_x -= floor(w->p.wall_x);
	if (n == 6)
	{
		if (w->p.side == 0 && w->p.raydir_x > 0)
			n = 3;
		if (w->p.side == 1 && w->p.raydir_y < 0)
			n = 1;
		if (w->p.side == 0 && w->p.raydir_x < 0)
			n = 2;
		if (w->p.side == 1 && w->p.raydir_y > 0)
			n = 5;
	}
	w->t[n].tex_x = (int)(w->p.wall_x * (double)w->t[n].tex_w);
	w->t[n].tex_x = w->t[n].tex_w - w->t[n].tex_x - 1;
	ft_sides_of_wall(w, x, n);
}
