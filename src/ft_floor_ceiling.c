/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:19:49 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/23 18:19:50 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	ft_wall_direction(t_info *w)
{
	if (w->p.side == 0 && w->p.raydir_x > 0)
	{
		w->fc.floor_wall_x = w->m.map_x;
		w->fc.floor_wall_y = w->m.map_y + w->p.wall_x;
	}
	else if (w->p.side == 0 && w->p.raydir_x < 0)
	{
		w->fc.floor_wall_x = w->m.map_x + 1.0;
		w->fc.floor_wall_y = w->m.map_y + w->p.wall_x;
	}
	else if (w->p.side == 1 && w->p.raydir_y > 0)
	{
		w->fc.floor_wall_x = w->m.map_x + w->p.wall_x;
		w->fc.floor_wall_y = w->m.map_y;
	}
	else
	{
		w->fc.floor_wall_x = w->m.map_x + w->p.wall_x;
		w->fc.floor_wall_y = w->m.map_y + 1.0;
	}
}

static void	ft_draw_floor_ceiling(t_info *w, int x, int y)
{
	double	weight;
	double	cur_fl_x;
	double	cur_fl_y;

	w->fc.cur_dist = H / (2.0 * y - H);
	weight = (w->fc.cur_dist - w->fc.dist_player) /
		(w->fc.dist_wall - w->fc.dist_player);
	cur_fl_x = weight * w->fc.floor_wall_x + (1.0 - weight) * w->p.pos_x;
	cur_fl_y = weight * w->fc.floor_wall_y + (1.0 - weight) * w->p.pos_y;
	w->fc.fl_tex_x = (int)(cur_fl_x * w->f[1].tex_w) % w->f[1].tex_w;
	w->fc.fl_tex_y = (int)(cur_fl_y * w->f[1].tex_h) % w->f[1].tex_h;
	w->color = (w->f[1].str[(int)w->f[1].tex_h *
		w->fc.fl_tex_y + w->fc.fl_tex_x] >> 1) & 8355711;
	ft_put_pixel(w, x, y, w->color);
	w->color = (w->f[0].str[(int)w->f[0].tex_w *
		w->fc.fl_tex_y + w->fc.fl_tex_x]);
	ft_put_pixel(w, x, H - y, w->color);
}

void		ft_floor_ceiling(t_info *w, int x)
{
	int y;

	ft_wall_direction(w);
	w->fc.dist_wall = w->p.pwall_dist;
	w->fc.dist_player = 0.0;
	if (w->p.y1 < 0)
		w->p.y1 = H;
	y = w->p.y1 + 1;
	while (y < H)
	{
		ft_draw_floor_ceiling(w, x, y);
		y++;
	}
}
