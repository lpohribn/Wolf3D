/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:55:38 by lpohribn          #+#    #+#             */
/*   Updated: 2018/03/25 13:55:44 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	ft_ahead(t_info *w)
{
	if (w->map[(int)(w->p.pos_x + w->p.dir_x
		* (w->p.mvspeed + 0.2))][(int)(w->p.pos_y)] == 0)
		w->p.pos_x += w->p.dir_x * w->p.mvspeed;
	if (w->map[(int)(w->p.pos_x)][(int)(w->p.pos_y + w->p.dir_y
		* (w->p.mvspeed + 0.2))] == 0)
		w->p.pos_y += w->p.dir_y * w->p.mvspeed;
}

static void	ft_back(t_info *w)
{
	if (w->map[(int)(w->p.pos_x - w->p.dir_x
		* (w->p.mvspeed + 0.2))][(int)(w->p.pos_y)] == 0)
		w->p.pos_x -= w->p.dir_x * w->p.mvspeed;
	if (w->map[(int)(w->p.pos_x)][(int)(w->p.pos_y - w->p.dir_y
		* (w->p.mvspeed + 0.2))] == 0)
		w->p.pos_y -= w->p.dir_y * w->p.mvspeed;
}

static void	ft_left(t_info *w)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = w->p.dir_x;
	old_plane_x = w->p.plane_x;
	w->p.dir_x = w->p.dir_x * cos(w->p.rotspeed)
		- w->p.dir_y * sin(w->p.rotspeed);
	w->p.dir_y = old_dir_x * sin(w->p.rotspeed)
		+ w->p.dir_y * cos(w->p.rotspeed);
	w->p.plane_x = w->p.plane_x * cos(w->p.rotspeed)
		- w->p.plane_y * sin(w->p.rotspeed);
	w->p.plane_y = old_plane_x * sin(w->p.rotspeed)
		+ w->p.plane_y * cos(w->p.rotspeed);
}

static void	ft_right(t_info *w)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = w->p.dir_x;
	old_plane_x = w->p.plane_x;
	w->p.dir_x = w->p.dir_x * cos(-w->p.rotspeed)
	- w->p.dir_y * sin(-w->p.rotspeed);
	w->p.dir_y = old_dir_x * sin(-w->p.rotspeed)
	+ w->p.dir_y * cos(-w->p.rotspeed);
	w->p.plane_x = w->p.plane_x * cos(-w->p.rotspeed)
	- w->p.plane_y * sin(-w->p.rotspeed);
	w->p.plane_y = old_plane_x * sin(-w->p.rotspeed)
	+ w->p.plane_y * cos(-w->p.rotspeed);
}

void		ft_move(t_info *w)
{
	if (w->fl.right == 1)
		ft_right(w);
	if (w->fl.left == 1)
		ft_left(w);
	if (w->fl.up == 1)
		ft_ahead(w);
	if (w->fl.down == 1)
		ft_back(w);
}
