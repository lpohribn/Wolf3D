/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:48:28 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/17 16:48:30 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	ft_dda2(t_info *w, int step_x, int step_y)
{
	if (w->p.side == 0)
		w->p.pwall_dist = (w->m.map_x - w->p.pos_x +
			(1 - step_x) / 2) / w->p.raydir_x;
	else
		w->p.pwall_dist = (w->m.map_y - w->p.pos_y +
			(1 - step_y) / 2) / w->p.raydir_y;
	w->p.line_h = (int)(H / w->p.pwall_dist);
	w->p.y0 = -w->p.line_h / 2 + H / 2;
	if (w->p.y0 < 0)
		w->p.y0 = 0;
	w->p.y1 = w->p.line_h / 2 + H / 2;
	if (w->p.y1 >= H)
		w->p.y1 = H - 1;
}

static void	ft_dda1(t_info *w, int step_x, int step_y)
{
	w->p.hit = 0;
	while (w->p.hit == 0)
	{
		if (w->p.sdist_x < w->p.sdist_y)
		{
			w->p.sdist_x += w->p.ddist_x;
			w->m.map_x += step_x;
			w->p.side = 0;
		}
		else
		{
			w->p.sdist_y += w->p.ddist_y;
			w->m.map_y += step_y;
			w->p.side = 1;
		}
		if (w->map[w->m.map_x][w->m.map_y] > 0)
			w->p.hit = 1;
	}
	ft_dda2(w, step_x, step_y);
}

static void	ft_dda(t_info *w)
{
	int step_x;
	int step_y;

	if (w->p.raydir_x < 0)
	{
		step_x = -1;
		w->p.sdist_x = (w->p.pos_x - w->m.map_x) * w->p.ddist_x;
	}
	else
	{
		step_x = 1;
		w->p.sdist_x = (w->m.map_x + 1.0 - w->p.pos_x) * w->p.ddist_x;
	}
	if (w->p.raydir_y < 0)
	{
		step_y = -1;
		w->p.sdist_y = (w->p.pos_y - w->m.map_y) * w->p.ddist_y;
	}
	else
	{
		step_y = 1;
		w->p.sdist_y = (w->m.map_y + 1.0 - w->p.pos_y) * w->p.ddist_y;
	}
	ft_dda1(w, step_x, step_y);
}

int			ft_raycasting(t_info *w)
{
	int x;

	x = 0;
	while (x < W)
	{
		w->p.cam_x = 2 * x / (double)W - 1;
		w->p.raydir_x = w->p.dir_x + w->p.plane_x * w->p.cam_x;
		w->p.raydir_y = w->p.dir_y + w->p.plane_y * w->p.cam_x;
		w->m.map_x = (int)w->p.pos_x;
		w->m.map_y = (int)w->p.pos_y;
		w->p.ddist_x = fabs(1 / w->p.raydir_x);
		w->p.ddist_y = fabs(1 / w->p.raydir_y);
		ft_dda(w);
		ft_draw_texture(w, x);
		ft_floor_ceiling(w, x);
		x++;
	}
	return (0);
}
